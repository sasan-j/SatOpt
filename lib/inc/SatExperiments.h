/*
 * File:   SatExperiments.h
 * Author: snjix
 *
 * Created on June 15, 2013, 5:05 PM
 */

#ifndef SATEXPERIMENTS_H
#define	SATEXPERIMENTS_H


#include <vector>
#include <string>
#include "SatOpt.h"
#include "SatOptStats.h"
#include "RunResult.h"

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

	std::vector < SatOptObjectiveVector> frontNormalizerSat(const std::vector < SatOptObjectiveVector > & _set, std::vector < eoRealInterval > &_bounds /*vectors contains bounds for normalization*/)
	{
	    //cout << "Sat norm\n";
	    std::vector < SatOptObjectiveVector > front;
	    front.resize(_set.size());
	    for(unsigned int i=0; i < _set.size(); i++)
	    {
	        front[i].resize(SatOptObjectiveVector::Traits::nObjectives());
	        for (unsigned int j=0; j<SatOptObjectiveVector::Traits::nObjectives(); j++)
	        {
	            if (SatOptObjectiveVector::Traits::minimizing(j))
	            {
	                //front[i][j]=abs((_set[i][j] - _bounds[j].minimum()) /_bounds[j].range());
					front[i][j]=1.0f - abs((_set[i][j] - _bounds[j].minimum()) /_bounds[j].range());
	            	//cout << front[i][j] << " ";

	            }
	            else
	            {
	                front[i][j]=((_set[i][j] - _bounds[j].minimum()) /_bounds[j].range());
	            }
	        }
	        //cout << endl;
	    }
	    //cout << "Sat norm end\n";

	    return front;
	}

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

	std::vector < std::vector<double> > frontNormalizer(const std::vector < SatOptObjectiveVector > & _set, std::vector < eoRealInterval > _bounds)
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
#ifdef DEBUG_INFO
					cout << " orig: " << _set[i][j] << "  ";
					cout << front[i][j] << " " << "boundRange " << _bounds[j].range();
#endif
				}
				else
				{
					front[i][j]=((_set[i][j] - _bounds[j].minimum()) /_bounds[j].range());
				}
			}
#ifdef DEBUG_INFO
			cout << endl;
#endif
		}
		return front;
    }

	std::vector<SatOptObjectiveVector> frontNormalizerObjVec(const std::vector < SatOptObjectiveVector > & _set, std::vector < eoRealInterval > _bounds)
    				{
		//std::vector < std::vector<double> > front;
		vector<SatOptObjectiveVector> front;
		front.resize(_set.size());
		for(unsigned int i=0; i < _set.size(); i++)
		{
			front[i].resize(SatOptObjectiveVector::Traits::nObjectives());
			for (unsigned int j=0; j<SatOptObjectiveVector::Traits::nObjectives(); j++)
			{
				if (SatOptObjectiveVector::Traits::minimizing(j))
				{
					front[i][j]=1.0f - abs((_set[i][j] - _bounds[j].minimum()) /_bounds[j].range());
#ifdef DEBUG_INFO
					cout << " orig: " << _set[i][j] << "  ";
					cout << front[i][j] << " "; //<< "
					cout << "boundRange " << _bounds[j].range();
#endif
				}
				else
				{
					front[i][j]=((_set[i][j] - _bounds[j].minimum()) /_bounds[j].range());
				}
			}
#ifdef DEBUG_INFO
			cout << endl;
#endif
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
		//moeoUnboundedArchive<SatOpt>optFront(false);
		//optimalFront = optFront ;//was false
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
					if ((int)((*iter2).objectiveVector(0)) != (*iter2).objectiveVector(0))
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

	void extractExactOrTrueFront(){
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
		vector<SatOptObjectiveVector> tmpOptimalFrontObjVector;
		moeoUnboundedArchive<SatOpt> tmpOptimalFront;//was false (false)
		///////////////////////////////////////////////////////////
		for(int i=0; i<4; i++)
		{
			vector<RunResult> results=this->fullResults[i];
			for(unsigned int i=0; i<results.size(); i++)
			{
				tmpOptimalFront(results[i].finalArchive);
			}
			//cout << "generated optimila" << endl;
			//optimalFront.sortedPrintOn(cout);
		}
		this->optimalFront(tmpOptimalFront);
		//this loop extracts objective vectors of generated optimal front into new vector
		for(unsigned int i=0; i<this->optimalFront.size(); i++)
		{
			tmpOptimalFrontObjVector.push_back(this->optimalFront[i].objectiveVector());
		}
		this->optimalFrontObjVector=tmpOptimalFrontObjVector;
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
			resultsObjVectors.push_back(optimalFrontObjVector);
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

		cout << "maxLPL " << maxLPL << " maxSW " << maxSwChanges << endl;
		cout << "minLPL " << minLPL << " minSW " << minSwChanges << endl;

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


		refPoint[0]=maxLPL;
		refPoint[1]=maxSwChanges;

		refFront[0]=maxLPL;
		refFront[1]=maxSwChanges;
		////////////////////////////////////////////////////////
	}

	void calculateUnaryHV( vector<RunResult> *results, vector< vector<SatOptObjectiveVector> >*resultsObjVectors)
	{
		moeoHyperVolumeMetric < SatOptObjectiveVector > hyperVolumeMetricUnary(false,refPoint);



		std::vector<RunResult>::iterator ResultIterator;
		int i=0;
		for (ResultIterator = results->begin();
				ResultIterator != results->end();ResultIterator++ )
		{

			//hyperVolDiff.setup(optimalFrontObjVector,resultsObjVectors[i]);
			//cout << "HyperVolume: " << hyperVolumeMetricUnary(resultsObjVectors[i]) << endl;
			try
			{
				std::vector < std::vector<double> > currentFrontNorm=frontNormalizer((*resultsObjVectors)[i],bounds);
				//cout << "unary HV: " << hyperVolumeMetricUnary.calc_hypervolume(currentFrontNorm,currentFrontNorm.size(),2) << endl;
				double unaryHV = hyperVolumeMetricUnary.calc_hypervolume(currentFrontNorm,currentFrontNorm.size(),2);
				//cout << "unaryHV: " << unaryHV << endl;
				(*ResultIterator).setUnaryHyperVol(unaryHV);
				//cout << "unaryHV: " << (*ResultIterator).getUnaryHyperVol() << endl;
			}
			catch (exception& e)
			{
				cout << "unary hypervolume error is: " << e.what()  << endl;
				(*ResultIterator).setUnaryHyperVol(333);
			}
			i++;
		}
		//cout << "HyperVolume: " << hyperVolumeMetricUnary(optimalFrontObjVector) << endl;
		std::vector < std::vector<double> > trueFrontNorm=frontNormalizer(optimalFrontObjVector,bounds);
		trueFrontUnaryHV=hyperVolumeMetricUnary.calc_hypervolume(trueFrontNorm,trueFrontNorm.size(),2);
	}


	void calculateBinaryDiffHV(vector<RunResult> *results, vector< vector<SatOptObjectiveVector> >*resultsObjVectors){
		SatOptObjectiveVector refPoint;
		refPoint[0]=1.0f;
		refPoint[1]=1.0f;
		moeoHyperVolumeDifferenceMetric <SatOptObjectiveVector>hyperVolDiff(true, refPoint);
		//moeoHypervolumeBinaryMetric <SatOptObjectiveVector>hyperVolBinary(1.1);
		vector<SatOptObjectiveVector> trueFrontNorm=frontNormalizerObjVec(optimalFrontObjVector,bounds);
		//cout << "\nBinary Hyper volume is:" << endl;
		//This loop calculates and print the hyperVolumeDiff
		for(unsigned int i=0; i<results->size(); i++)
		{
			//changed from greater to greater or equal to test new assumption!
			if(optimalFrontObjVector.size() > 0 && (*resultsObjVectors)[i].size() > 0)
			{
				vector<SatOptObjectiveVector> currentFrontNorm=frontNormalizerObjVec((*resultsObjVectors)[i],bounds);
				//cout << "hyperDiff: " << hyperVolDiff(optimalFrontObjVector,resultsObjVectors[i]) << endl;
				try
				{
					//double binaryHV=hyperVolDiff(optimalFrontObjVector,(*resultsObjVectors)[i]);
					double binaryHV=hyperVolDiff(currentFrontNorm,trueFrontNorm);
					(*results)[i].setBinaryHyperVol(binaryHV);
					//cout << "binaryHV: " << binaryHV << endl;

					//results[i].setBinaryHyperVol(hyperVolBinary(optimalFrontObjVector,optimalFrontObjVector));
				}
				catch (exception& e)
				{
					cout << "error is: " << e.what()  << endl;
					(*results)[i].setBinaryHyperVol(333);
				}

			}
			else (*results)[i].setBinaryHyperVol(333);
		}
	}

	void calculateBinaryAdditiveEpsilon(vector<RunResult> *results, vector< vector<SatOptObjectiveVector> >*resultsObjVectors){

		moeoVecVsVecAdditiveEpsilonBinaryMetric < SatOptObjectiveVector > additiveEpsilon(false);
		vector<SatOptObjectiveVector> trueFrontNorm=frontNormalizerObjVec(optimalFrontObjVector,bounds);
		//This loop calculates and print the AdditiveEpsilonBinaryMetric
		for(unsigned int i=0; i<results->size(); i++)
		{

			if(optimalFrontObjVector.size() > 0 && (*resultsObjVectors)[i].size() > 0)
			{
				vector<SatOptObjectiveVector> currentFrontNorm=frontNormalizerObjVec((*resultsObjVectors)[i],bounds);
				//hyperVolDiff.setup(optimalFrontObjVector,resultsObjVectors[i]);
				//cout << "additiveEpsilon: " << additiveEpsilon(resultsObjVectors[i],optimalFrontObjVector) << endl;
				try
				{
					//double epsilon=additiveEpsilon((*resultsObjVectors)[i],optimalFrontObjVector);
					double epsilon=additiveEpsilon(trueFrontNorm,currentFrontNorm);
					(*results)[i].setAdditiveEps(epsilon);
					//cout << "epsilon: " << epsilon << endl;

				}
				catch (exception& e)
				{
					cout << "error is: " << e.what()  << endl;
					(*results)[i].setAdditiveEps(333);
				}
			}
			else (*results)[i].setAdditiveEps(333);
		}

	}

	void calculateBinaryEntropy(vector<RunResult> *results, vector< vector<SatOptObjectiveVector> >*resultsObjVectors){
		//This loop calculates and print the entropyMetric
		vector<SatOptObjectiveVector> trueFrontNorm=frontNormalizerObjVec(optimalFrontObjVector,bounds);
		moeoEntropyMetric < SatOptObjectiveVector > entropyMetric;
		for(unsigned int i=0; i<results->size(); i++)
		{

			if(optimalFrontObjVector.size() > 0 && (*resultsObjVectors)[i].size() > 0)
			{
				vector<SatOptObjectiveVector> currentFrontNorm=frontNormalizerObjVec((*resultsObjVectors)[i],bounds);
				//by swapping the inputs we will get constant value for all, i don't know why
				try
				{
					//(*results)[i].setEntropy(entropyMetric((*resultsObjVectors)[i],optimalFrontObjVector));
					//cout << "before calc entropy in try\n";
					(*results)[i].setEntropy(entropyMetric(currentFrontNorm,trueFrontNorm));
				}
				catch (exception& e)
				{
					cout << "error is: " << e.what() << endl;
					(*results)[i].setEntropy(333);
				}
			}
			else (*results)[i].setEntropy(333);
		}
	}

	void writeResultsToTxt(vector<RunResult> *results, int l){
		sprintf(temp,"final_res_%d_%d_%d_%d.txt",chCount,l,swInst,chInst);//i stands for algo
		string fResultFileName=temp;
		remove((resultDir+fResultFileName).c_str());
		ofstream  finalResFile(resultDir+fResultFileName, ios::app);

		unsigned int tmpGenCount;
		double tmpElapsedTime;
		double tmpUnaryHV;
		double tmpBinaryHV;
		double tmpEpsilon;
		double tmpEntropy;
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


			std::vector<RunResult>::iterator ResultIterator;
			int i=0;
			for (ResultIterator = results->begin();
					ResultIterator != results->end();ResultIterator++ )
			{
				tmpGenCount=(*ResultIterator).getGenCount();
				tmpElapsedTime=(*ResultIterator).getElapsedTime();
				tmpUnaryHV=(*ResultIterator).getUnaryHyperVol();
				tmpBinaryHV=(*ResultIterator).getBinaryHyperVol();
				tmpEpsilon=(*ResultIterator).getAdditiveEps();
				tmpEntropy=(*ResultIterator).getEntropy();

				finalResFile << "runNumber " 		<< i << endl;
				finalResFile << "genCount " 		<< tmpGenCount << endl;
				finalResFile << "elapsedTime " 		<< tmpElapsedTime << endl;
				finalResFile << "unaryHyperVol " 	<< tmpUnaryHV << endl;
				finalResFile << "binaryHyperVol " 	<< tmpBinaryHV << endl;
				finalResFile << "additiveEps " 		<< tmpEpsilon << endl;
				finalResFile << "entropy " 		<< tmpEntropy << endl;
				finalResFile << "archive " 		<< i << endl;
				(*ResultIterator).finalArchive.sortedPrintOn(finalResFile);


				/////////////DEBUG INFO//////////////////////////
#ifdef DEBUG_INFO
				cout << "runNumber " 		<< i << endl;
				cout << "genCount " 		<< tmpGenCount << endl;
				cout << "elapsedTime " 		<< tmpElapsedTime << endl;
				cout << "unaryHyperVol " 		<< tmpUnaryHV << endl;
				cout << "binaryHyperVol " 	<< tmpBinaryHV << endl;
				cout << "additiveEps " 		<< tmpEpsilon << endl;
				cout << "entropy " 		<< tmpEntropy << endl;
				cout << "archive " 		<< i << endl;
				(*ResultIterator).finalArchive.sortedPrintOn(cout);
#endif
				///////////////////////////////////////////////////
				i++;
			}


			finalResFile.close();
		}
	}
	void writeResultsToCSV(int l){
		vector<RunResult> results=this->fullResults[l];
		sprintf(temp,"final_res_%d_%d_%d_%d.csv",chCount,l,swInst,chInst);//i stands for algo
		string fResultCSVFileName=temp;
		remove((resultDir+fResultCSVFileName).c_str());
		ofstream  finalResCSVFile(resultDir+fResultCSVFileName, ios::app);

		if (finalResCSVFile.is_open())
		{
			finalResCSVFile << "runNumber," << "genCount," << "elapsedTime," << "noSolutions,"
					<< "unaryHyperVol," << "binaryHyperVol," << "additiveEps," << "entropy\r\n";

			std::vector<RunResult>::iterator ResultIterator;
			int i=0;
			for (ResultIterator = results.begin();
					ResultIterator != results.end();ResultIterator++ )
			{
				finalResCSVFile << i << ","
						<< (*ResultIterator).getGenCount() << ","
						<< (*ResultIterator).getElapsedTime() << ","
						<< (*ResultIterator).finalArchive.size() << ","
						<< (*ResultIterator).getUnaryHyperVol() << ","
						<< (*ResultIterator).getBinaryHyperVol() << ","
						<< (*ResultIterator).getAdditiveEps() << ","
						<< (*ResultIterator).getEntropy() << "\r\n";

				//////DEBUG INFO///////////////////////////////////
#ifdef DEBUG_INFO
				cout << i << ","
						<< (*ResultIterator).getGenCount() << ","
						<< (*ResultIterator).getElapsedTime() << ","
						<< (*ResultIterator).finalArchive.size() << ","
						<< (*ResultIterator).getUnaryHyperVol() << ","
						<< (*ResultIterator).getBinaryHyperVol() << ","
						<< (*ResultIterator).getAdditiveEps() << ","
						<< (*ResultIterator).getEntropy() << "\r\n";
#endif
				/////////////////////////////////////////////////////////
				i++;
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


		std::vector< std::vector< std::vector<SatOptObjectiveVector> > >::iterator resultsObjVectorsVectIterator;
		std::vector< std::vector<RunResult> >::iterator fullResultsIterator;

		int l =0;
		//iterator loop for algorithms
		fullResultsIterator = this->fullResults.begin();
		for(resultsObjVectorsVectIterator = this->resultsObjVectorsVect.begin();
				resultsObjVectorsVectIterator != this->resultsObjVectorsVect.end();
				resultsObjVectorsVectIterator++,fullResultsIterator++,l++)
		{
#ifdef DEBUG_INFO
cout << "before unaryHV\n";
#endif
			calculateUnaryHV(&(*fullResultsIterator), &(*resultsObjVectorsVectIterator));
#ifdef DEBUG_INFO
cout << "before binaryHV\n";
#endif
			calculateBinaryDiffHV(&(*fullResultsIterator), &(*resultsObjVectorsVectIterator));
#ifdef DEBUG_INFO
cout << "before binaryEps\n";
#endif
			calculateBinaryAdditiveEpsilon(&(*fullResultsIterator), &(*resultsObjVectorsVectIterator));
#ifdef DEBUG_INFO
cout << "before binary ent\n";
#endif
			calculateBinaryEntropy(&(*fullResultsIterator), &(*resultsObjVectorsVectIterator));
			writeResultsToCSV(l);
			writeResultsToTxt(&(*fullResultsIterator),l);
		}

	}

};

#endif	/* SATEXPERIMENTS_H */
