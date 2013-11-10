/*
 * File:   main.cpp
 * Author: sasan
 *
 * Created on March 28, 2013, 2:40 PM
 */

#include <cstdlib>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdexcept>
#include <ga/eoBitOp.h>

#include <es/eoRealInitBounded.h>
#include <es/eoRealOp.h>
#include <stdio.h>
#include <eo>
#include <ga.h>
#include <moeo>
//#include<eoCellularEasyEA.h>
#include<eoContinue.h>
#include<eoSecondsElapsedContinue.h>

//my codes
#include "Node.h"
#include "Port.h"
#include "PrIns.h"
#include "Payload.h"
#include "../inc/eoBitOp_.h"
#include "../inc/moeoNSGAII_snj.h"
#include <time.h>       /* time */
#include <ctime>
#include <string>
#include <chrono>
//#include "CTimer.h"
#include "SatOpt.h"
#include "RunResult.h"
#include "FileAccess.h"
#include "Payload_100.h"

//for getExact
#include <fstream>
#include <iostream>
#include <sstream> //this is where istringstream is defined
#include <vector>

//#define DEBUG_ALL

using namespace std;

enum ALGO { NSGA2,SPEA2,IBEA,MOGA };


//samplePayload.Payload();
PrIns *p1 = new PrIns("initial");
Payload *samplePayload= new Payload;
Payload_100 *payloadObject100 = new Payload_100;
vector<int> initSwitchPos;
vector<string> chan_instance; //says which channel should connect to amp
string resultDir = "result/";




class MyException:public exception
{
public:
    MyException(const string m)
    {
        msg=m;
    }
    //~MyException(void);
    const char* what()
    {
        return msg.c_str();
    }
private:
    string msg;
};

// evaluation of objective functions

class SatOptEval : public moeoEvalFunc < SatOpt >
{
public:

    void operator () (SatOpt & _satOpt)
    {
        if (_satOpt.invalidObjectiveVector())
        {


            vector<int> tmpVector;
            vector<int> switchPos;


            for (unsigned i = 0; i < _satOpt.size(); i++)
            {
                tmpVector.push_back(_satOpt[i]); //load individual into tmpVector
            }

            //converting int vector of the individual (tmpVector) into
            //another vector representing switch state
            //each two bit -> one switch state
            int result;
            for (unsigned int g = 0; g <= tmpVector.size() - 2; g = g + 2)
            {
                int x = tmpVector[g];
                int y = tmpVector[g + 1];
                if (x == 0 && y == 0)
                {
                    result = 1;
                }
                else if (x == 1 && y == 0)
                {
                    result = 2;
                }
                else if (x == 0 && y == 1)
                {
                    result = 3;
                }
                else
                {
                    result = 4;
                }
                switchPos.push_back(result);
            }

            vector<double> evalResult;

            if(p1->getSwCount()==50){
                evalResult = samplePayload->run(switchPos, chan_instance);
                //cout << "channel instance calling " << chan_instance.size() << endl;
                //cout << "channel instance calling " << chan_instance[0] << endl;
                }
            else
                evalResult = payloadObject100->run(switchPos, chan_instance);
            //////////////////////////////////////////////////////////////////
            int switchChanges = 0;
            for (unsigned int i = 0; i < switchPos.size(); i++)
            {
                if (switchPos[i] != initSwitchPos[i])
                    switchChanges++;
            }

            //////////////////////////////////////////////////////////////////

            SatOptObjectiveVector objVec;


            if (!(((int)(evalResult[0]))== evalResult[0]))// penalty for switch changes
            {
                switchChanges = evalResult[0];// + switchChanges;
            }

            objVec[0] = evalResult[0]; //quality metric LPL
            objVec[1] = switchChanges;
            //objVec[2] = evalResult[1];//constructed paths
            //objVec[3] = evalResult[2];//longest path

            _satOpt.objectiveVector(objVec);
        }
    }
};

class SatOptStats : public moeoObjVecStat<SatOpt >
{
    string str;
    SatOptEval eval;
    RunResult *currentResult;

    moeoUnboundedArchive < SatOpt > arch;
    std::vector < std::vector<double> >frontVector;
    unsigned int genCount;
public:
    ALGO algo;

    SatOptStats(string _str) : moeoObjVecStat <SatOpt > ()
    {
        str = _str;
        genCount = 0;
    }

    void operator()(const eoPop<SatOpt>& _pop)
    {
        //genCount++;
        this->currentResult->incGenCount();
        if((int)algo!=3)
	     doit(_pop);
    }

    void setCurrentResult(RunResult *_result)
    {
        this->currentResult = _result;
    }
private:

    void doit(const eoPop<SatOpt> &_pop)
    {
        moeoUnboundedArchive < SatOpt > tempArch;
        tempArch(_pop);
        if(!arch.equals(tempArch))
        {
            ofstream file (resultDir+this->currentResult->resultFileName, ios::app);
            if (file.is_open())
            {
                //now current archive should flush into result file
                file << "genCount " << this->currentResult->genCount << endl;
                arch(tempArch);
                //cout should change to the file output stream
                arch.sortedPrintOn(file);
                file.close();
            }

        }
    }

    /*
        void popDiversityCalc(const eoPop<SatOpt> &_pop){
            vector<string> strPop;
            vector<string> uniquePop;
            for(unsigned int i = 0; i < _pop.size();i++)
            {
                string strIndi="";
                for(int j = 0; j<_pop[i].size();j++){
                    strIndi+=_pop[i][j];
                }
                strPop.push_back(strIndi);
            }
            for(unsigned int i = 0; i < strPop.size(); i++){
                if(isNew(uniquePop,strPop[i]))
                    uniquePop.push_back(strPop[i]);
            }
            cout << "unique indi's are: " << uniquePop.size() << endl;
        }

        bool isNew(vector<string> &uniquePop,string indi){
            for(unsigned int i = 0;i < uniquePop.size();i++){
                if(indi.compare(uniquePop[i]))
                    return false;
            }
            return true;
        }
      */
};




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
    eoBitMutation<SatOpt> mutation(p1->getProbMut(),true);


    eoSGATransform<SatOpt>settings(xover, 0.8, mutation, 1.0);

    // fill it!
    for (unsigned int igeno = 0; igeno < p1->getPopSize(); igeno++)
    {
        SatOpt v; // void individual, to be filled
        for (unsigned ivar = 0; ivar < p1->getVectorSize(); ivar++)
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

    eoSecondsElapsedContinue<SatOpt> continuatorMaxTime(p1->getMaxTime());
    eoGenContinue<SatOpt> continuatorMaxGen(p1->getMaxGen());
    eoCheckPoint<SatOpt> checkpoint(continuatorMaxTime);

    SatOptStats satStats("haha");
    satStats.setCurrentResult(&result);
    ///////////////////////////////////////////////////////////////////////
    satStats.algo=algo;
    checkpoint.add(satStats);

    eoSteadyFitContinue<SatOpt> continuatorMaxSteady(p1->getMinGen(),p1->getIdleGen());

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

    result.elapsedTime = elapsed_seconds.count();


    file.open(resultDir+runFileName, ios::app);
    if (file.is_open())
    {
        file << "DONE after " << result.genCount << " generations." << endl;
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




// exact fron extractor
class ExactExtractor
{

private:
    unsigned int chCount;
    unsigned int swInst;
    unsigned int chInst;
    vector<SatOptObjectiveVector> optimalFront;

public:

    ExactExtractor(unsigned int _swInst, unsigned int _chCount ,unsigned int _chInst)
    {
        swInst = _swInst+1;//because in the files swInst starts from 1 not 0
        chCount = _chCount;
        chInst = _chInst;
    }

    bool isAvailable()
    {
        std::string fileName;
        bool found=false;
        std::ifstream infile;
        std::string line;
        std::vector<std::string> lines;
        std::string compareStr;
        int a,b;
        switch (chCount)
        {
        case 8:
            fileName="ref/ExactResults/Pareto_size8/NEW_Correct_Pareto_Points_"+std::to_string(swInst)+"_"+std::to_string(chInst)+".txt";
            //std::cout << "file name is "<< fileName << std::endl;
            infile.open(fileName.c_str());
            if (infile.is_open())
            {
                found = true;
                while ( infile.good() )
                {
                    //cout << "reads the file" << endl;
                    getline (infile,line);
                    if(line.length() > 2)
                    {
                        //cout << line << endl;
                        sscanf(line.c_str(),"%d,%d\n",&a,&b);
                        //cout << "the values read from file\n";
                        //cout << a << endl << b << endl;
                        SatOptObjectiveVector objVec;
                        objVec[0] = a; //quality metric LPL
                        objVec[1] = b;
                        optimalFront.push_back(objVec);
                    }
                    else
                        break;

                }
                cout << optimalFront.size() << endl;
                infile.close();
            }
            break;
        case 13:
        case 18:
            fileName="ref/ExactResults/ParetoPoints"+std::to_string(chCount)+".txt";
            cout << fileName << endl;
            //std::cout << "file name is "<< fileName << std::endl;
            infile.open(fileName.c_str());
            while ( infile.good() )
            {
                //cout << "reads the file" << endl;

                getline (infile,line);
                //cout << line << endl;
                if(line.length()>5)
                    lines.push_back(line);
                //cout << lines.size() << endl;
            }
            infile.close();
            compareStr="Pareto front found for "+std::to_string(swInst)+"_"+std::to_string(chInst);
            for(std::vector<std::string>::size_type i=0; i<lines.size(); i++)
            {
                //cout << "-----------------" << endl;
                //cout << lines[i] << endl;
                //cout << compareStr << endl;
                if(lines[i].find(compareStr)!=std::string::npos)
                {
                    found = true;
                    i++;
                    while(lines[i].find(" Pareto")== std::string::npos)
                    {
                        sscanf(lines[i].c_str(),"(%d,%d)\n",&a,&b);
                        //cout << "the values read from file\n";
                        //cout << a << endl << b << endl;
                        SatOptObjectiveVector objVec;
                        objVec[0] = a; //quality metric LPL
                        objVec[1] = b;
                        optimalFront.push_back(objVec);
                        i++;
                    }
                    break;
                }
            }

            break;
        case 25:
        case 30:
        case 35:
            return false;
        default:
            return false;
        }
        return found;
    }

    std::vector<SatOptObjectiveVector> getExactFront(void)
    {
        return optimalFront;
    }


};


// main

int main_function(int argc, char *argv[])
{
    eoParser parser(argc, argv); // for user-parameter reading

    eoState state; // to keep all things allocated

    // parameters
    unsigned int POP_SIZE = parser.createParam((unsigned int) (100), "popSize", "Population size", 'P', "Param").value();
    unsigned int MAX_GEN = parser.createParam((unsigned int) (100000), "maxGen", "Maximum number of generations", 'G', "Param").value();
    unsigned int MIN_GEN = parser.createParam((unsigned int) (50000), "minGen", "Minimum number of generations", 'H', "Param").value();
    unsigned int IDLE_GEN = parser.createParam((unsigned int) (50000), "idleGen", "Maximum number of useless generations!", 'I', "Param").value();

    double M_EPSILON = parser.createParam(0.01, "mutEpsilon", "epsilon for mutation", 'e', "Param").value();
    double P_CROSS = parser.createParam(0.8, "pCross", "Crossover probability", 'C', "Param").value();
    double P_MUT = parser.createParam(1.0, "pMut", "Mutation probability final result would be P_MUT/chrom_lenght", 'M', "Param").value();
    unsigned int MAX_TIME = parser.createParam((unsigned int) (6), "maxTime", "Maximum execution time", 'T', "Param").value();
    //unsigned int SEED = parser.createParam((unsigned int) (1), "seed", "Seed for population generation", 'S', "Param").value();
    unsigned int algo = parser.createParam((unsigned int) (0), "algo", "Algo to use, NSGA2=0 SPEA2=1 IBEA=2 MOGA=3", 'A', "Param").value();
    unsigned int runs = parser.createParam((unsigned int) (5), "runs", "Number of runs", 'R', "Param").value();
    unsigned int swInst = parser.createParam((int) (1), "swInst", "Switch initial position instance 0-29", 'U', "Param").value();
    unsigned int chInst = parser.createParam((int) (1), "chInst", "Channels to connect, instance 0-29", 'V', "Param").value();
    unsigned int chCount = parser.createParam((int) (35), "chCount", "Number of channels 8-13-18-23", 'W', "Param").value();
    unsigned int swCount = parser.createParam((int) (100), "swCount", "Number of payload switches 50 or 100", 'S', "Param").value();

    eoValueParam<string> switchInst("32112442144331313411332124112141422433134132413232", "Initial Switch Positions", "This parameter specifies the initial position of the switches", 'S');
    parser.processParam(switchInst, "switchInst");
    eoValueParam<string> probinst("E1,E7,G13,G3,G9,TG1,TG9,E3", "Channels to connect", "Channels that we want to connect to amplifier", 'O');
    parser.processParam(probinst, "probinst");
    string instance = probinst.value();
    const unsigned int VEC_SIZE = swCount*2; //184;   // Number of bits in genotypes


    FileAccess fileAcc;
    vector<string> chanInstanceStr;
    bool isExactAvailable =  false;

    //cout << "Now get instances " << chInst << " " << chCount << endl;


    if(chInst<30 && chCount<40)
    {
        vector<string> chanInstanceStr;
        chanInstanceStr=fileAcc.getChanInstance(chCount,chInst);
        if(chanInstanceStr.size()>0)
        {
            cout << chanInstanceStr[0] << " " << chanInstanceStr[1] << endl;
            p1->setName(chanInstanceStr[1]);
        }
        else
            throw MyException("Check that if ref folder and its contents are available-channel");

    }
    else
    {
        //cout << "Instance is " << instance << endl;
        p1->setName(instance);
    }
    //cout << p1->getName() << endl;
    chan_instance = p1->getChannels();

    string switchInstStr;

    if(swInst<30)
    {
        vector<string> swInstanceStr;
        swInstanceStr=fileAcc.getSwInstance(swCount, swInst);
        if(swInstanceStr.size()>0)
        {
            cout << swInstanceStr[0] << " " << swInstanceStr[1] << endl;
            switchInstStr=swInstanceStr[1];
        }
        else
            throw MyException("Check that if ref folder and its contents are available-switch");
    }
    else
    {
        switchInstStr = switchInst.value();
    }


    //cout << "Initial Switch Positions " << switchInstStr << endl;

    make_help(parser);

    p1->setPopSize(POP_SIZE);
    p1->setVectorSize(VEC_SIZE);
    p1->setIdleGen(IDLE_GEN);
    p1->setMaxGen(MAX_GEN);
    p1->setMaxTime(MAX_TIME);
    p1->setMinGen(MIN_GEN);
    p1->setProbMut(P_MUT);
    p1->setSwCount(swCount);

    vector<int> switchPos;

    if (switchInstStr.length() == VEC_SIZE / 2)
    {
        //cout << "Switch positions are given by the user!" << endl;
        int x;
        for (unsigned int i = 0; i < VEC_SIZE / 2; i++)
        {
            x = switchInstStr[i] - 48; //converting ascii code of char numbers to integers
            switchPos.push_back(x);
            //cout << x;
        }
        //cout << endl;
    }
    else
    {
        if (switchInstStr.length() > 0)
            cout << "The given switch positions is invalid, so let's generate some random positions!" << endl;
        else
            cout << "No switch position specified so let's generate some random positions!" << endl;
        /////////////////////////////
        for (unsigned i = 0; i < VEC_SIZE / 2; i++)
        {
            // generate secret number between 1 and 4:
            switchPos.push_back(rng.rand() % 4 + 1);
            //cout << switchPos[i];
        }
    }

    p1->setInitSwitchPos(switchPos);
    initSwitchPos = p1->getInitSwitchPos();


    cout << "channel inst " << p1->getName() << endl << "switch inst " << switchInstStr << endl;



    /*
     char temp[256];
     sprintf(temp,"final_res_%d_%d_%d_%d.txt",chCount,algo,swInst,chInst);
     string fResultFileName=temp;
     remove((resultDir+fResultFileName).c_str());
     ofstream  finalResFile(resultDir+fResultFileName, ios::app);
     if (finalResFile.is_open())
     {
         finalResFile.close();
     }
     */
    /////////////////////////
    /////////////////////////
    ///////////////////////
    vector< vector<RunResult> > fullResults;

    for(int i=0; i<4; i++)
    {
        vector<RunResult> results;
        results=runJob((ALGO)i, chCount, swInst, chInst, runs);
        fullResults.push_back(results);
    }


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

    moeoUnboundedArchive<SatOpt> optimalFront(false);//was false
    vector<SatOptObjectiveVector> optimalFrontObjVector;


    ExactExtractor ep = ExactExtractor(swInst,chCount,chInst);
    if(ep.isAvailable())
    {
        //cout << "exact found" << endl;
        optimalFrontObjVector = ep.getExactFront();
        isExactAvailable = true;
    }
    else
    {
        //cout << "exact not found" << endl;
        //filling the optimal front
        for(int i=0; i<4; i++)
        {
            vector<RunResult> results=fullResults[i];
            for(unsigned int i=0; i<results.size(); i++)
            {
                optimalFront(results[i].finalArchive);
            }
            //cout << "generated optimila" << endl;
            //optimalFront.sortedPrintOn(cout);
        }
        //this loop extracts objective vectors of generated optimal front into new vector
        for(unsigned int i=0; i<optimalFront.size(); i++)
        {
            optimalFrontObjVector.push_back(optimalFront[i].objectiveVector());
        }
    }

    vector< vector< vector<SatOptObjectiveVector> > > resultsObjVectorsVect;


    for(int i=0; i<4; i++)
    {
        vector<RunResult> results=fullResults[i];
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
        resultsObjVectorsVect.push_back(resultsObjVectors);
    }

    //calculate objective extremes
    double maxLPL=0;
    double maxSwChanges=0;
    for(int i=0; i<4; i++)
    {
        vector< vector<SatOptObjectiveVector> >resultsObjVectors;
        resultsObjVectors = resultsObjVectorsVect[i];
        for(unsigned int i=0; i<resultsObjVectors.size(); i++)
        {
            for(int j=0; j<resultsObjVectors[i].size(); j++)
            {
                SatOptObjectiveVector resultObjVector=resultsObjVectors[i][j];
                if(resultObjVector[0]>=maxSwChanges)
                    maxSwChanges=resultObjVector[0];
                if(resultObjVector[1]>=maxLPL)
                    maxLPL=resultObjVector[1];
            }
        }
    }

    //cout << maxLPL << endl << maxSwChanges;


    SatOptObjectiveVector refFront;
    refFront[0]=maxSwChanges;
    refFront[1]=maxLPL;
    moeoHyperVolumeMetric < SatOptObjectiveVector > hyperVolumeMetricUnary(false,refFront);


    for(int l=0; l<4; l++)
    {
        vector<RunResult> results=fullResults[l];
        vector< vector<SatOptObjectiveVector> >resultsObjVectors;
        resultsObjVectors = resultsObjVectorsVect[l];
        for(unsigned int i=0; i<results.size(); i++)
        {

            //hyperVolDiff.setup(optimalFrontObjVector,resultsObjVectors[i]);
            //cout << "HyperVolume: " << hyperVolumeMetricUnary(resultsObjVectors[i]) << endl;
            try
            {
                results[i].setUnaryHyperVol(hyperVolumeMetricUnary(resultsObjVectors[i]));
            }
            catch (exception& e)
            {
                cout << "unary hypervolume error is: " << e.what()  << endl;
                results[i].setUnaryHyperVol(333);
            }
        }

        //cout << "HyperVolume: " << hyperVolumeMetricUnary(optimalFrontObjVector) << endl;
        //hyperVolumeMetricUnary(optimalFrontObjVector);

        moeoHyperVolumeDifferenceMetric <SatOptObjectiveVector>hyperVolDiff(false, refFront);
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
                    if(i<(results.size()-2))
                        cout << "entropyMetric: " << entropyMetric(resultsObjVectors[i],resultsObjVectors[i+1]) << endl;
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

        char temp[256];
        sprintf(temp,"final_res_%d_%d_%d_%d.txt",chCount,l,swInst,chInst);//i stands for algo
        string fResultFileName=temp;
        remove((resultDir+fResultFileName).c_str());
        ofstream  finalResFile(resultDir+fResultFileName, ios::app);
        //finalResFile.open(resultDir+fResultFileName, ios::app);
        if (finalResFile.is_open())
        {
            finalResFile << "OptimalFront" << endl;
            finalResFile << "unaryHyperVol " << hyperVolumeMetricUnary(optimalFrontObjVector)  << endl;
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
                finalResFile << "runNumber " << i << endl;
                finalResFile << "genCount " << results[i].genCount << endl;
                finalResFile << "elapsedTime " << results[i].elapsedTime << endl;
                finalResFile << "unaryHyperVol " << results[i].getUnaryHyperVol() << endl;
                finalResFile << "binaryHyperVol " << results[i].getBinaryHyperVol() << endl;
                finalResFile << "additiveEps " << results[i].getAdditiveEps() << endl;
                finalResFile << "entropy " << results[i].getEntropy() << endl;
                finalResFile << "archive " << i << endl;
                results[i].finalArchive.sortedPrintOn(finalResFile);
            }
            finalResFile.close();
        }


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
                                << results[i].genCount << ","
                                << results[i].elapsedTime << ","
                                << results[i].finalArchive.size() << ","
                                << results[i].getUnaryHyperVol() << ","
                                << results[i].getBinaryHyperVol() << ","
                                << results[i].getAdditiveEps() << ","
                                << results[i].getEntropy() << "\r\n";
            }
            try
            {
                finalResCSVFile << ",,," << hyperVolumeMetricUnary(optimalFrontObjVector) << ",,,";
            }
            catch (exception& e)
            {
                cout << "optimal front unary hypervolume error is: " << e.what()  << endl;
                finalResCSVFile << ",,,333,,,";
            }


            finalResCSVFile.close();
        }


    }









    return EXIT_SUCCESS;
}


// A main that catches the exceptions

int main(int argc, char **argv)
{

    try
    {
        //std::to_string(5);
        main_function(argc, argv);
    }
    catch (MyException& e)
    {
        cout << "Exception: " << e.what() << '\n';
    }
    catch (exception& e)
    {
        cout << "Exception: " << e.what() << '\n';
    }


    return 0;
}
