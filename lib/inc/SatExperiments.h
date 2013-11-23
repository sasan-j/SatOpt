
#include <vector>
#include <string>
#include "SatOpt.h"
#include "SatOptStats.h"

class SatExperiment {
private:
  bool isExactAvailable =  false;
  PrIns* currentPrInst;
  vector< vector<RunResult> > fullResults;
  unsigned int chCount, swInst, chInst, runs;
  string resultDir;
  moeoUnboundedArchive<SatOpt> optimalFront;//was false (false)
  vector<SatOptObjectiveVector> optimalFrontObjVector;
  vector< vector< vector<SatOptObjectiveVector> > > resultsObjVectorsVect;
  double maxLPL;
  double minLPL;
  double maxSwChanges;
  double minSwChanges;
  SatOptObjectiveVector refPoint;
  std::vector < eoRealInterval > bounds;
  SatOptObjectiveVector refFront;
  char temp[256];
  double trueFrontUnaryHV;

vector<RunResult> runJob(ALGO algo, int chCount, int swInst, int chInst,unsigned int numRuns)
{
    vector<RunResult> results;

    //creates results directory
    mkdir(resultDir.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH); //with read/write/search permissions for owner and group, and with read/search permissions for others.
    unsigned int SEED=1;
    for (unsigned int i = 0; i < numRuns; i++)
    {
	char temp[256];
	sprintf(temp,"run_res_%d_%d_%d_%d_%d.txt",chCount,algo,swInst,chInst,i);
	string runFileName=temp;
	results.push_back(runAlgo(algo, runFileName, SEED)); //i acts as seed
	SEED++;
    }
    return results;
}
  
  RunResult runAlgo(ALGO algo, string runFileName, unsigned int SEED)
{
    // generate initial population
    eoPop < SatOpt > pop;
    rng.reseed(time(NULL));
    RunResult result;
    result.resultFileName = runFileName;
    remove((resultDir+runFileName).c_str());

    //for time calculations
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    std::time_t start_time = std::chrono::system_clock::to_time_t(start);
    ofstream file (resultDir+runFileName, ios::app);
    if (file.is_open())
    {
	file << "START at " << std::ctime(&start_time) << endl;
	file.close();
    }


    // objective functions evaluation
    SatOptEval eval;

    // crossover and mutation
    //eoQuadCloneOp < SatOpt > xover;
    //eo1PtBitXover<SatOpt> xover;
    eoNPtsBitXoverCustom<SatOpt> xover;
    //the probability would be P_MUT/chrome_size because the second argument which is true!(it is for doing normalization)
    eoBitMutation<SatOpt> mutation(currentPrInst->getProbMut(),true);


    eoSGATransform<SatOpt>settings(xover, 0.8, mutation, 1.0);

    // fill it!
    for (unsigned int igeno = 0; igeno < currentPrInst->getPopSize(); igeno++)
    {
	SatOpt v; // void individual, to be filled
	for (unsigned ivar = 0; ivar < currentPrInst->getVectorSize(); ivar++)
	{
	    bool r = rng.flip(); // new value, random in {0,1}
	    v.push_back(r); // append that random value to v
	}
	eval(v); // evaluate it
	pop.push_back(v); // and put it in the population
    }

    // shuffle  - this is a test
    pop.shuffle();
    //pop.sortedPrintOn(cout);




    //////////////////////////////////////
    // termination condition
    /////////////////////////////////////

    eoSecondsElapsedContinue<SatOpt> continuatorMaxTime(currentPrInst->getMaxTime());
    eoGenContinue<SatOpt> continuatorMaxGen(currentPrInst->getMaxGen());
    eoCheckPoint<SatOpt> checkpoint(continuatorMaxTime);

    SatOptStats satStats(resultDir);
    satStats.setCurrentResult(&result);
    ///////////////////////////////////////////////////////////////////////
    satStats.algo=algo;
    checkpoint.add(satStats);

    eoSteadyFitContinue<SatOpt> continuatorMaxSteady(currentPrInst->getMinGen(),currentPrInst->getIdleGen());

    eoCombinedContinue<SatOpt> continuator(continuatorMaxSteady);

    //continuator.add(continuatorMaxSteady);
    continuator.add(checkpoint);
    continuator.add(continuatorMaxGen);


    if (algo == NSGA2)
    {
	cout << "algo is NSGA-II" << endl;
	// build NSGA-II
	moeoNSGAII_snj < SatOpt > nsgaII(continuator, eval, settings);
	// run the algo
	nsgaII(pop);
    }
    else if (algo == SPEA2)
    {
	cout << "algo is SPEA-II" << endl;
	////SPEA2
	moeoUnboundedArchive < SatOpt > arch_speaII;
	moeoSPEA2 < SatOpt >speaII(continuator, eval, settings, arch_speaII, 1, false);
	speaII(pop);
	result.setFinalArchiveFromPop(arch_speaII);
    }
    else if (algo == IBEA)
    {
	cout << "algo is IBEA" << endl;
	// build IBEA
	//moeoHyperVolumeDifferenceMetric <SatOptObjectiveVector>metricVector(true, 1.1);
	moeoHypervolumeBinaryMetric <SatOptObjectiveVector>metricVector(1.1);
	//moeoAdditiveEpsilonBinaryMetric < SatOptObjectiveVector > metricVector;
	moeoIBEA < SatOpt > ibea(continuator, eval, settings, metricVector, 0.05);
	// run the algo
	ibea(pop);
    }
    else if (algo == MOGA)
    {
	cout << "algo is MOGA" << endl;
	// build MOGA
	moeoMOGA < SatOpt > moga(continuator, eval, settings);
	// run the algo
	moga(pop);
    }

    if(algo != SPEA2)
	result.setFinalArchiveFromPop(pop);

    //////////////////////////////
    //time calculations///////////
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    result.setElapsedTime(elapsed_seconds.count());


    file.open(resultDir+runFileName, ios::app);
    if (file.is_open())
    {
	file << "DONE after " << result.getGenCount() << " generations." << endl;
	file << "Finished computation at " << std::ctime(&end_time)
	    << "elapsed time: " << elapsed_seconds.count() << "s" << endl;
	file.close();
    }
    /////////////////////
    /////////////////////
    /*
    // printing of the final archive
    cout << "\nFinal Archive" << endl;
    cout << "Switch Changes\tLPL\n";
    arch.sortedPrintOn(cout);
    cout << endl << "Final Population" << endl;
    */
    //timer->End();
    //result.setElapsedTime(timer->GetTimeInSeconds());
    return result;
}

    std::vector < std::vector<double> > frontNormalizer(const std::vector < SatOptObjectiveVector > & _set, std::vector < eoRealInterval > _bounds ,SatOptObjectiveVector ref_point)
    {
        std::vector < std::vector<double> > front;
        front.resize(_set.size());
        for(unsigned int i=0; i < _set.size(); i++)
        {
            front[i].resize(SatOptObjectiveVector::Traits::nObjectives());
            for (unsigned int j=0; j<SatOptObjectiveVector::Traits::nObjectives(); j++)
            {
                if (SatOptObjectiveVector::Traits::minimizing(j))
                {
                    front[i][j]=1.0f - abs((_set[i][j] - _bounds[j].minimum()) /_bounds[j].range());
                    //cout << " orig: " << _set[i][j] << "  ";
                    //cout << front[i][j] << " "; //<< "
                    //boundRange " << _bounds[j].range();

                }
                else
                {
                    front[i][j]=((_set[i][j] - _bounds[j].minimum()) /_bounds[j].range()) - ref_point[j];
                }
            }
            //cout << endl;
        }
        return front;
    }
 
    std::vector < std::vector<double> > frontNormalizerRef(const std::vector < SatOptObjectiveVector > & _set, std::vector < eoRealInterval > _bounds,SatOptObjectiveVector ref_point)
{
    std::vector < std::vector<double> > front;
    front.resize(_set.size());
    for(unsigned int i=0; i < _set.size(); i++)
    {
	front[i].resize(SatOptObjectiveVector::Traits::nObjectives());
	for (unsigned int j=0; j<SatOptObjectiveVector::Traits::nObjectives(); j++)
	{
	    if (SatOptObjectiveVector::Traits::minimizing(j))
	    {
		front[i][j]=ref_point[j] - abs((_set[i][j] - _bounds[j].minimum()) /_bounds[j].range());
		//cout << "orig: " << _set[i][j] << "  ";
		//cout << front[i][j] << "   ";
	    }
	    else
	    {
		front[i][j]=((_set[i][j] - _bounds[j].minimum()) /_bounds[j].range()) - ref_point[j];
	    }
	}
	//cout << endl;
    }
    return front;
}
 
 
public:
    //ctor
  SatExperiment(PrIns* tmpPrInst,unsigned int tmpChCount,unsigned int tmpSwInst,unsigned int tmpChInst,unsigned int tmpRuns, string tmpResultDir){
    currentPrInst = tmpPrInst;
    chCount = tmpChCount;
    swInst = tmpSwInst;
    chInst = tmpChInst;
    runs = tmpRuns;
    resultDir=tmpResultDir;
    maxLPL=0;
    minLPL=100;
    maxSwChanges=0;
    minSwChanges=100;
    //optimalFront = new moeoUnboundedArchive<SatOpt>(false);//was false
  }
  void runExperiments(void){
    for(int i=0; i<4; i++)
    {
	vector<RunResult> results;
	results=runJob((ALGO)i, chCount, swInst, chInst, runs);
	this->fullResults.push_back(results);
    }
  }
  
  void validateResults(){
    //this method removes invalid solutions from final results
    typename vector<RunResult>::iterator iter1;
    typename eoPop<SatOpt>::iterator iter2;
    for(int i=0; i<4; i++)
    {
	//vector<RunResult> results=fullResults[i];
	iter1 = fullResults[i].begin();
	//iter2++;
	//int popSize = _pop.size();
	for (; iter1 != fullResults[i].end(); )
	{
	    //std::cout << "first for\n";
	    iter2 = (*iter1).finalArchive.begin();
	    for (; iter2 != (*iter1).finalArchive.end();)
	    {
		if ((int)(*iter2).objectiveVector(0) != (*iter2).objectiveVector(0))
		{
		    (*iter1).finalArchive.erase(iter2);
		}
		else
		    ++iter2;
	    }
	    ++iter1;
	}
    }
  }
  
  void extractExactOrTrueFron(){
    ExactExtractor ep = ExactExtractor(swInst,chCount,chInst);
    if(ep.isAvailable())
    {
	//cout << "exact found" << endl;
	optimalFrontObjVector = ep.getExactFront();
	isExactAvailable = true;
    }
    else
    {
	extractTrueFront();
    }
  }
  void extractTrueFront(void){
    //filling the optimal front
    ///////////////////////////////////////////////////////////
    for(int i=0; i<4; i++)
    {
      vector<RunResult> results=this->fullResults[i];
      for(unsigned int i=0; i<results.size(); i++)
      {
	this->optimalFront(results[i].finalArchive);
      }
      //cout << "generated optimila" << endl;
      //optimalFront.sortedPrintOn(cout);
    }
    //this loop extracts objective vectors of generated optimal front into new vector
    for(unsigned int i=0; i<this->optimalFront.size(); i++)
    {
      optimalFrontObjVector.push_back(this->optimalFront[i].objectiveVector());
    }
    ////////////////////////////////////////////////////////////
  }
  
  void extractObjVectors(void){
        // we extract objective vectors from actual results
    ///////////////////////////////////////////////////
    for(int i=0; i<4; i++)
    {
	vector<RunResult> results=this->fullResults[i];
	vector< vector<SatOptObjectiveVector> >resultsObjVectors;
	//This piece of code extracts objective vectors from archives and put all of them into new vector
	for(unsigned int i=0; i<results.size(); i++)
	{
	    vector<SatOptObjectiveVector> resultObjVectors;
	    for(int j=0; j<results[i].finalArchive.size(); j++)
	    {
		resultObjVectors.push_back(results[i].finalArchive[j].objectiveVector());
	    }
	    resultsObjVectors.push_back(resultObjVectors);
	}
	this->resultsObjVectorsVect.push_back(resultsObjVectors);
    }
    //////////////////////////////////////////////////////  
  }
  
  void calculateBounds (void){
        //calculate objective extremes
    ////////////////////////////////////////////////////////
	for(int i=0; i<4; i++)
	{
	    //cout << i << endl;

	    vector< vector<SatOptObjectiveVector> >resultsObjVectors;
	    resultsObjVectors = this->resultsObjVectorsVect[i];
	    for(unsigned int j=0; j<resultsObjVectors.size(); j++)
	    {
		vector<SatOptObjectiveVector> resultObjVector=resultsObjVectors[j];

		for(unsigned int k=0; k<resultObjVector.size(); k++)
		{
		    //SatOptObjectiveVector resultObjVector=resultsObjVectors[j];
		    //cout << resultObjVector[k][0] << " " << resultObjVector[k][1] << endl;
		    //Maximums

		    if(resultObjVector[k][0]>=maxLPL)
			maxLPL=resultObjVector[k][0];
		    if(resultObjVector[k][1]>=maxSwChanges)
			maxSwChanges=resultObjVector[k][1];

		    //Minimums
		    if(resultObjVector[k][0]<=minLPL)
			minLPL=resultObjVector[k][0];
		    if(resultObjVector[k][1]<=minSwChanges)
			minSwChanges=resultObjVector[k][1];
		}
	    }
	}


	if(maxLPL==minLPL)
	{
	    minLPL=0;
	}
	if(maxSwChanges==minSwChanges)
	{
	    minSwChanges=0;
	}

	//cout << "maxLPL " << maxLPL << " maxSW " << maxSwChanges << endl;
	//cout << "minLPL " << minLPL << " minSW " << minSwChanges << endl;

	eoRealInterval bound= eoRealInterval(minLPL,maxLPL);
	eoRealInterval bound1=eoRealInterval(minSwChanges,maxSwChanges);
	bounds.push_back(bound);
	bounds.push_back(bound1);
	//instBounds=bounds;

	vector<SatOptObjectiveVector> setupObjVector;
	SatOptObjectiveVector objVectMin;
	objVectMin[0]=minLPL;
	objVectMin[1]=minSwChanges;
	setupObjVector.push_back(objVectMin);

	SatOptObjectiveVector objVectMax;
	objVectMax[0]=maxLPL;
	objVectMax[1]=maxSwChanges;
	setupObjVector.push_back(objVectMax);


	refPoint[0]=0;//maxLPL;
	refPoint[1]=0;//maxSwChanges;
	
	refFront[0]=maxSwChanges;
	refFront[1]=maxLPL;
    ////////////////////////////////////////////////////////
  }
  
  void calculateUnaryHV(vector<RunResult> results, vector< vector<SatOptObjectiveVector> >resultsObjVectors)
  {
        moeoHyperVolumeMetric < SatOptObjectiveVector > hyperVolumeMetricUnary(false,refFront);
    	for(unsigned int i=0; i<results.size(); i++)
	{

	    //hyperVolDiff.setup(optimalFrontObjVector,resultsObjVectors[i]);
	    //cout << "HyperVolume: " << hyperVolumeMetricUnary(resultsObjVectors[i]) << endl;
	    try
	    {
	      
	      std::vector < std::vector<double> > currentFrontNorm=frontNormalizer(resultsObjVectors[i],bounds,refPoint);
	      //cout << "unary HV: " << hyperVolumeMetricUnary.calc_hypervolume(currentFrontNorm,currentFrontNorm.size(),2) << endl;
	      results[i].setUnaryHyperVol(hyperVolumeMetricUnary.calc_hypervolume(currentFrontNorm,currentFrontNorm.size(),2));
	    }
	    catch (exception& e)
	    {
		cout << "unary hypervolume error is: " << e.what()  << endl;
		results[i].setUnaryHyperVol(333);
	    }
	}
	//cout << "HyperVolume: " << hyperVolumeMetricUnary(optimalFrontObjVector) << endl;
	std::vector < std::vector<double> > currentFrontNorm=frontNormalizer(optimalFrontObjVector,bounds,refPoint);
	trueFrontUnaryHV=hyperVolumeMetricUnary.calc_hypervolume(currentFrontNorm,currentFrontNorm.size(),2);
  }
  
  
    void calculateBinaryDiffHV(vector<RunResult> results, vector< vector<SatOptObjectiveVector> >resultsObjVectors){
  	moeoHyperVolumeDifferenceMetric <SatOptObjectiveVector>hyperVolDiff(true, refFront);
	//moeoHypervolumeBinaryMetric <SatOptObjectiveVector>hyperVolBinary(1.1);
	//cout << "\nBinary Hyper volume is:" << endl;
	//This loop calculates and print the hyperVolumeDiff
	for(unsigned int i=0; i<results.size(); i++)
	{
	    if(optimalFrontObjVector.size() > 0 && resultsObjVectors[i].size() > 0)
	    {
		//cout << "hyperDiff: " << hyperVolDiff(optimalFrontObjVector,resultsObjVectors[i]) << endl;
		try
		{
		    results[i].setBinaryHyperVol(hyperVolDiff(optimalFrontObjVector,resultsObjVectors[i]));
		    //results[i].setBinaryHyperVol(hyperVolBinary(optimalFrontObjVector,optimalFrontObjVector));
		}
		catch (exception& e)
		{
		    cout << "error is: " << e.what()  << endl;
		    results[i].setBinaryHyperVol(333);
		}

	    }
	    else results[i].setBinaryHyperVol(333);
	}
  }
  
  void calculateBinaryAdditiveEpsilon(vector<RunResult> results, vector< vector<SatOptObjectiveVector> >resultsObjVectors){
    
    	moeoVecVsVecAdditiveEpsilonBinaryMetric < SatOptObjectiveVector > additiveEpsilon(true);
	//This loop calculates and print the AdditiveEpsilonBinaryMetric
	for(unsigned int i=0; i<results.size(); i++)
	{

	    if(optimalFrontObjVector.size() > 0 && resultsObjVectors[i].size() > 0)
	    {
		//hyperVolDiff.setup(optimalFrontObjVector,resultsObjVectors[i]);
		//cout << "additiveEpsilon: " << additiveEpsilon(resultsObjVectors[i],optimalFrontObjVector) << endl;
		try
		{
		    results[i].setAdditiveEps(additiveEpsilon(resultsObjVectors[i],optimalFrontObjVector));
		}
		catch (exception& e)
		{
		    cout << "error is: " << e.what()  << endl;
		    results[i].setAdditiveEps(333);
		}
	    }
	    else results[i].setAdditiveEps(333);
	}
    
  }

  void calculateBinaryEntropy(vector<RunResult> results, vector< vector<SatOptObjectiveVector> >resultsObjVectors){
    	//This loop calculates and print the entropyMetric
	for(unsigned int i=0; i<results.size(); i++)
	{
	    moeoEntropyMetric < SatOptObjectiveVector > entropyMetric;



	    if(optimalFrontObjVector.size() > 0 && resultsObjVectors[i].size() > 0)
	    {
		//by swapping the inputs we will get constant value for all, i don't know why

		try
		{
		    results[i].setEntropy(entropyMetric(resultsObjVectors[i],optimalFrontObjVector));
		    //if(i<(results.size()-2))
			//cout << "entropyMetric: " << entropyMetric(resultsObjVectors[i],resultsObjVectors[i+1]) << endl;
		    //cout << "entropyMetric: " << entropyMetric(optimalFrontObjVector,resultsObjVectors[i]) << endl;

		}
		catch (exception& e)
		{
		    cout << "error is: " << e.what() << endl;
		    results[i].setEntropy(333);
		}

	    }
	    else results[i].setEntropy(333);

	}
  }
  
  void writeResultsToTxt(vector<RunResult> results, int l){
	sprintf(temp,"final_res_%d_%d_%d_%d.txt",chCount,l,swInst,chInst);//i stands for algo
	string fResultFileName=temp;
	remove((resultDir+fResultFileName).c_str());
	ofstream  finalResFile(resultDir+fResultFileName, ios::app);

	//finalResFile.open(resultDir+fResultFileName, ios::app);
	if (finalResFile.is_open())
	{
	    finalResFile << "OptimalFront" << endl;
	    finalResFile << "unaryHyperVol " << trueFrontUnaryHV << endl;
	    if(isExactAvailable)
	    {
		finalResFile << "Optimal front is obtained by exact method\n-------------------------\n";
		finalResFile << optimalFrontObjVector.size() << endl;
		for(std::vector<SatOptObjectiveVector>::size_type i=0;i<optimalFrontObjVector.size();i++){
		    finalResFile << optimalFrontObjVector[i][0] << " " << optimalFrontObjVector[i][1] << endl;
		}
	    }
	    else
	    {
		optimalFront.sortedPrintOn(finalResFile);
		finalResFile << "-------------------------\n";
	    }

	    for(unsigned int i=0; i<results.size(); i++)
	    {
		finalResFile << "runNumber " 		<< i << endl;
		finalResFile << "genCount " 		<< results[i].getGenCount() << endl;
		finalResFile << "elapsedTime " 		<< results[i].getElapsedTime() << endl;
	        finalResFile << "unaryHyperVol " 	<< results[i].getUnaryHyperVol() << endl;
		finalResFile << "binaryHyperVol " 	<< results[i].getBinaryHyperVol() << endl;
		finalResFile << "additiveEps " 		<< results[i].getAdditiveEps() << endl;
		finalResFile << "entropy " 		<< results[i].getEntropy() << endl;
		finalResFile << "archive " 		<< i << endl;
		results[i].finalArchive.sortedPrintOn(finalResFile);
		
		
		
		cout << "runNumber " 		<< i << endl;
		cout << "genCount " 		<< results[i].getGenCount() << endl;
		cout << "elapsedTime " 		<< results[i].getElapsedTime() << endl;
		cout << "unaryHyperVol " 		<< results[i].getUnaryHyperVol() << endl;
		cout << "binaryHyperVol " 	<< results[i].getBinaryHyperVol() << endl;
		cout << "additiveEps " 		<< results[i].getAdditiveEps() << endl;
		cout << "entropy " 		<< results[i].getEntropy() << endl;
		cout << "archive " 		<< i << endl;
		results[i].finalArchive.sortedPrintOn(cout);
	    }
	    finalResFile.close();
	}
  }
  void writeResultsToCSV(vector<RunResult> results, int l){
    
    	sprintf(temp,"final_res_%d_%d_%d_%d.csv",chCount,l,swInst,chInst);//i stands for algo
	string fResultCSVFileName=temp;
	remove((resultDir+fResultCSVFileName).c_str());
	ofstream  finalResCSVFile(resultDir+fResultCSVFileName, ios::app);

	if (finalResCSVFile.is_open())
	{
	    finalResCSVFile << "runNumber," << "genCount," << "elapsedTime," << "noSolutions,"
			    << "unaryHyperVol," << "binaryHyperVol," << "additiveEps," << "entropy\r\n";

	    for(unsigned int i=0; i<results.size(); i++)
	    {
		finalResCSVFile << i << ","
				<< results[i].getGenCount() << ","
				<< results[i].getElapsedTime() << ","
				<< results[i].finalArchive.size() << ","
				<< results[i].getUnaryHyperVol() << ","
				<< results[i].getBinaryHyperVol() << ","
				<< results[i].getAdditiveEps() << ","
				<< results[i].getEntropy() << "\r\n";
				
				
				
				
		cout << i << ","
				<< results[i].getGenCount() << ","
				<< results[i].getElapsedTime() << ","
				<< results[i].finalArchive.size() << ","
				<< results[i].getUnaryHyperVol() << ","
				<< results[i].getBinaryHyperVol() << ","
				<< results[i].getAdditiveEps() << ","
				<< results[i].getEntropy() << "\r\n";
	    }
	    try
	    {
		finalResCSVFile << ",,," << trueFrontUnaryHV << ",,,";
	    }
	    catch (exception& e)
	    {
		cout << "optimal front unary hypervolume error is: " << e.what()  << endl;
		finalResCSVFile << ",,,333,,,";
	    }


	    finalResCSVFile.close();
	}
    
  }
  
  void calculateMetrics(void){
        


    for(int l=0; l<4; l++)
    {
      cout << "start of loop\n";
	vector<RunResult> results=this->fullResults[l];
	vector< vector<SatOptObjectiveVector> >resultsObjVectors;
	resultsObjVectors = this->resultsObjVectorsVect[l];
	      cout << "before unary\n";

	calculateUnaryHV(results, resultsObjVectors);
		      cout << "before diff\n";

	calculateBinaryDiffHV(results, resultsObjVectors);
	//	      cout << "before eps\n";

	calculateBinaryAdditiveEpsilon(results, resultsObjVectors);
	//	      cout << "before entropy\n";

	calculateBinaryEntropy(results, resultsObjVectors);
	writeResultsToCSV(results,l);
	writeResultsToTxt(results,l);

    }
    
  }
  
};

