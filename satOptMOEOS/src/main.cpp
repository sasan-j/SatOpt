/*
 * File:   main.cpp
 * Author: sasan
 *
 * Created on March 28, 2013, 2:40 PM
 */

#include <cstdlib>
#include <time.h>

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
//#include "CTimer.h"
#include "SatOpt.h"
#include "RunResult.h"
#include "FileAccess.h"

//#define DEBUG_ALL

using namespace std;

enum ALGO { NSGA2,SPEA2,IBEA,MOGA } ;


//samplePayload.Payload();
PrIns *p1 = new PrIns("initial");
Payload *samplePayload= new Payload;
vector<int> initSwitchPos;
vector<string> chan_instance; //this works, says which channel should connect to amp


// evaluation of objective functions

class SatOptEval : public moeoEvalFunc < SatOpt > {
public:

    void operator () (SatOpt & _satOpt) {
        if (_satOpt.invalidObjectiveVector()) {
            //string problem_instance = p1->getName();
            //vector<string> chan_instance; //this works, says which channel should connect to amp
            //chan_instance = p1->getChannels();
            //vector<int> initSwitchPos = p1->getInitSwitchPos();



            //cout << endl << problem_instance << endl;

            vector<int> tmpVector;
            vector<int> switchPos;

            /*
            for (int i =0; i<chan_instance.size();i++){
                cout << endl << chan_instance[i];
            }
             */

            for (unsigned i = 0; i < _satOpt.size(); i++) {
                tmpVector.push_back(_satOpt[i]); //load individual into tmpVector
            }
#ifdef DEBUG_ALL

            cout << "\nindividual size: " << tmpVector.size() << endl;
            cout << "individual size: " << _satOpt.size() << endl;

            for (int i = 0; i < tmpVector.size(); i++) {
                cout << tmpVector[i];
            }
            cout << endl;
#endif
            //converting int vector of the individual (tmpVector) into
            //another vector representing switch state
            //each two bit -> one switch state
            int result;
            for (int g = 0; g <= tmpVector.size() - 2; g = g + 2) {
                int x = tmpVector[g];
                int y = tmpVector[g + 1];
                if (x == 0 && y == 0) {
                    result = 1;
                } else if (x == 1 && y == 0) {
                    result = 2;
                } else if (x == 0 && y == 1) {
                    result = 3;
                } else {
                    result = 4;
                }
                switchPos.push_back(result);
            }
#ifdef DEBUG_ALL

            cout << endl << switchPos.size() << endl;

            for (int i = 0; i < switchPos.size(); i++) {
                cout << switchPos[i];
            }

#endif
            //switch position are available in vector switchPos
            //solution.push_back(0);

            //Node start("F11", "channel", 1, 0);
            vector<double> evalResult;
            //evalResult = start.run(solution, switchPos, 1, chan_instance);
            //Payload *samplePayload= new Payload;
            evalResult = samplePayload->run(switchPos, chan_instance);
            //start.~Node();
            //////////////////////////////////////////////////////////////////
            int difference = 0;
            for (int i = 0; i < switchPos.size(); i++) {
                if (switchPos[i] != initSwitchPos[i])
                    difference++;
            }

            int switchChanges = difference;
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

class SatOptStats : public moeoObjVecStat<SatOpt > {
    string str;
    SatOptEval eval;
    RunResult *currentResult;

    moeoUnboundedArchive < SatOpt > arch;
    std::vector < std::vector<double> >frontVector;
    //moeoArchive < SatOpt > arch;
    double hyp;
    unsigned int genCount;
public:

    SatOptStats(string _str) : moeoObjVecStat <SatOpt > () {
        str = _str;
        genCount = 0;
    }

    void operator()(const eoPop<SatOpt>& _pop) {
        genCount++;
        this->currentResult->incGenCount();
        //this->currentResult.genCount = genCount;
        doit(_pop);
    }

    void setCurrentResult(RunResult *_result){
        this->currentResult = _result;
    }
private:

    void doit(const eoPop<SatOpt> &_pop) {
        moeoUnboundedArchive < SatOpt > tempArch;
        tempArch(_pop);
        //tempArch.sortedPrintOn(cout);
        //eval(arch);
        //hyp = metric.calc_hypervolume(frontVector, frontVector.size(), 2);
        //cout << "Switch Changes\tLPL\n";
        if(!arch.equals(tempArch)){
                cout << "genCount " << genCount << endl;
                arch(tempArch);
                arch.sortedPrintOn(cout);
                //call additional methods after this comment!
                //hyperVolumeMetric();
                //popDiversityCalc(_pop);
        }
    }


/*
    void popDiversityCalc(const eoPop<SatOpt> &_pop){
        vector<string> strPop;
        vector<string> uniquePop;
        for(int i = 0; i < _pop.size();i++)
        {
            string strIndi="";
            for(int j = 0; j<_pop[i].size();j++){
                strIndi+=_pop[i][j];
            }
            strPop.push_back(strIndi);
        }
        for(int i = 0; i < strPop.size(); i++){
            if(isNew(uniquePop,strPop[i]))
                uniquePop.push_back(strPop[i]);
        }
        cout << "unique indi's are: " << uniquePop.size() << endl;
    }



    bool isNew(vector<string> &uniquePop,string indi){
        for(int i = 0;i < uniquePop.size();i++){
            if(indi.compare(uniquePop[i]))
                return false;
        }
        return true;
    }
  */
    void hyperVolumeMetric() {

        moeoHyperVolumeMetric < SatOptObjectiveVector > metric(false, false);
        SatOptObjectiveVector fitness;
        frontVector.clear();
        for (int i; i < arch.size(); i++) {
            vector<double> objVec;
            fitness = arch[i].objectiveVector();
            objVec.push_back(fitness[0]);
            objVec.push_back(fitness[1]);
            frontVector.push_back(objVec);
         }
         hyp = metric.calc_hypervolume(frontVector, frontVector.size(), 2);
         std::cout << "hypervolume is :" << hyp << std::endl;
    }

    void distanceMetric() {

        //moeoEuclideanDistance <SatOpt> dist;
        //SatOptObjectiveVector fitnessRef;
        //fitnessRef[0]=0;
        //fitnessRef[1]=1;
        //moeoDistanceMetric < SatOptObjectiveVector > metric(dist, fitnessRef);

    }

};




RunResult runAlgo(ALGO algo, unsigned int SEED){
       // generate initial population
    eoPop < SatOpt > pop;
    rng.reseed(time(NULL));
    RunResult result;
    //CTimer *timer = new CTimer;
    //timer->Start();

        // objective functions evaluation
    SatOptEval eval;

    // crossover and mutation
    //eoQuadCloneOp < SatOpt > xover;
    //eo1PtBitXover<SatOpt> xover;
    eoNPtsBitXoverCustom<SatOpt> xover;
    //eoNPtsBitXover<SatOpt> xover;
    //eoUniformMutation < SatOpt > mutation (M_EPSILON);
    //the probability would be P_MUT/chrome_size
    eoBitMutation<SatOpt> mutation(p1->getProbMut(),true);


    eoSGATransform<SatOpt>settings(xover, 0.8, mutation, 1.0);

    // fill it!
    for (unsigned int igeno = 0; igeno < p1->getPopSize(); igeno++) {
        SatOpt v; // void individual, to be filled
        for (unsigned ivar = 0; ivar < p1->getVectorSize(); ivar++) {
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
    checkpoint.add(satStats);

    eoSteadyFitContinue<SatOpt> continuatorMaxSteady(p1->getMinGen(),p1->getIdleGen());

    eoCombinedContinue<SatOpt> continuator(continuatorMaxSteady);

    //continuator.add(continuatorMaxSteady);
    continuator.add(checkpoint);
    continuator.add(continuatorMaxGen);


    if (algo == NSGA2) {
        cout << "algo is NSGA-II" << endl;
        // build NSGA-II
        moeoNSGAII_snj < SatOpt > nsgaII(continuator, eval, settings);
        // run the algo
        nsgaII(pop);
    } else if (algo == SPEA2) {
        cout << "algo is SPEA-II" << endl;
        ////SPEA2
        moeoUnboundedArchive < SatOpt > arch_speaII;
        moeoSPEA2 < SatOpt >speaII(continuator, eval, settings, arch_speaII, 1, false);
        speaII(pop);
        result.setFinalArchiveFromPop(arch_speaII);
    } else if (algo == IBEA) {
        cout << "algo is IBEA" << endl;
        // build IBEA
        moeoAdditiveEpsilonBinaryMetric < SatOptObjectiveVector > metricVector;
        moeoIBEA < SatOpt > ibea(continuator, eval, settings, metricVector, 0.05);
        // run the algo
        ibea(pop);
    } else if (algo == MOGA) {
        cout << "algo is MOGA" << endl;
        // build MOGA
        moeoMOGA < SatOpt > moga(continuator, eval, settings);
        // run the algo
        moga(pop);
    }

    if(algo != SPEA2)
        result.setFinalArchiveFromPop(pop);

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


vector<RunResult> runJob(ALGO algo, int numRuns){
    vector<RunResult> results;
    unsigned int SEED=1;
    for (unsigned int i = 0; i < numRuns; i++) {
        results.push_back(runAlgo(algo, SEED)); //i acts as seed
        SEED++;
    }
    return results;
}



// main

int main_function(int argc, char *argv[]) {
    eoParser parser(argc, argv); // for user-parameter reading

    eoState state; // to keep all things allocated

    // parameters
    unsigned int POP_SIZE = parser.createParam((unsigned int) (100), "popSize", "Population size", 'P', "Param").value();
    unsigned int MAX_GEN = parser.createParam((unsigned int) (5000), "maxGen", "Maximum number of generations", 'G', "Param").value();
    unsigned int MIN_GEN = parser.createParam((unsigned int) (200), "minGen", "Minimum number of generations", 'H', "Param").value();
    unsigned int IDLE_GEN = parser.createParam((unsigned int) (300), "idleGen", "Maximum number of useless generations!", 'I', "Param").value();

    double M_EPSILON = parser.createParam(0.01, "mutEpsilon", "epsilon for mutation", 'e', "Param").value();
    double P_CROSS = parser.createParam(0.8, "pCross", "Crossover probability", 'C', "Param").value();
    double P_MUT = parser.createParam(1.0, "pMut", "Mutation probability final result would be P_MUT/chrom_lenght", 'M', "Param").value();
    unsigned int MAX_TIME = parser.createParam((unsigned int) (600), "maxTime", "Maximum execution time", 'T', "Param").value();
    //unsigned int SEED = parser.createParam((unsigned int) (1), "seed", "Seed for population generation", 'S', "Param").value();
    unsigned int algo = parser.createParam((unsigned int) (0), "algo", "Algo to use, NSGA2=0 SPEA2=1 IBEA=2 MOGA=3", 'A', "Param").value();
    unsigned int runs = parser.createParam((unsigned int) (5), "runs", "Number of runs", 'R', "Param").value();

    const unsigned int VEC_SIZE = 100; //184;   // Number of bits in genotypes



    eoValueParam<string> probinst("E1,E7,G13,G3,G9,TG1,TG9,E3", "Channels to connect", "Channels that we want to connect to amplifier", 'O');
    parser.processParam(probinst, "probinst");
    string instance = probinst.value();
    cout << "Instance is " << instance << endl;
    p1->setName(instance);
    //cout << p1->getName() << endl;
    chan_instance = p1->getChannels();

    eoValueParam<string> switchInst("32112442144331313411332124112141422433134132413232", "Initial Switch Positions", "This parameter specifies the initial position of the switches", 'S');
    parser.processParam(switchInst, "switchInst");
    string switchInstStr = switchInst.value();
    //cout << "Initial Switch Positions " << switchInstStr << endl;

    make_help(parser);

    p1->setPopSize(POP_SIZE);
    p1->setVectorSize(VEC_SIZE);
    p1->setIdleGen(IDLE_GEN);
    p1->setMaxGen(MAX_GEN);
    p1->setMaxTime(MAX_TIME);
    p1->setMinGen(MIN_GEN);
    p1->setProbMut(P_MUT);

    vector<int> switchPos;

    if (switchInstStr.length() == VEC_SIZE / 2) {
        cout << "Switch positions are given by the user!" << endl;
        int x;
        for (int i = 0; i < VEC_SIZE / 2; i++) {
            x = switchInstStr[i] - 48; //converting ascii code of char numbers to integers
            switchPos.push_back(x);
            cout << x;
        }
        cout << endl;
    }
    else {
        if (switchInstStr.length() > 0)
            cout << "The given switch positions is invalid, so let's generate some random positions!" << endl;
        else
            cout << "No switch position specified so let's generate some random positions!" << endl;
        /////////////////////////////
        for (unsigned i = 0; i < VEC_SIZE / 2; i++) {
            // generate secret number between 1 and 4:
            switchPos.push_back(rng.rand() % 4 + 1);
            cout << switchPos[i];
        }
    }

    p1->setInitSwitchPos(switchPos);
    initSwitchPos = p1->getInitSwitchPos();

    vector<RunResult> results;
    results=runJob((ALGO)algo, runs);
    FileAccess fileAcc;
    fileAcc.getChanInstance(8,25);
    moeoUnboundedArchive<SatOpt> optimalFront(false);

    cout << "\nHere are the results:" << endl;

    for(int i=0;i<results.size();i++){
        cout << "Number of generations: " << results[i].genCount << endl;
        cout << "Elapsed time: " << results[i].elapsedTime << endl;
        results[i].finalArchive.sortedPrintOn(cout);
        optimalFront(results[i].finalArchive);
    }
    cout << "Generated optimal front is:" << endl;
    optimalFront.sortedPrintOn(cout);


    vector< vector<SatOptObjectiveVector> >resultsObjVectors;
    //This piece of code extracts objective vectors from archives and put all of them into new vector
    for(int i=0;i<results.size();i++){
        vector<SatOptObjectiveVector> resultObjVectors;
        for(int j=0;j<results[i].finalArchive.size();j++){
            resultObjVectors.push_back(results[i].finalArchive[j].objectiveVector());
        }
        resultsObjVectors.push_back(resultObjVectors);
    }

    //this loop extracts objective vectors of generated optimal front into new vector
    vector<SatOptObjectiveVector> optimalFrontObjVector;
    for(int i=0;i<optimalFront.size();i++){
        optimalFrontObjVector.push_back(optimalFront[i].objectiveVector());
    }




    /*SatOptObjectiveVector refFront;
    refFront[0]=20.0;
    refFront[1]=50.0;*/
    moeoHyperVolumeMetric < SatOptObjectiveVector > hyperVolumeMetricUnary(false, false /*refFront*/);
    for(int i=0;i<results.size();i++){
        //hyperVolDiff.setup(optimalFrontObjVector,resultsObjVectors[i]);
        cout << "HyperVolume: " << hyperVolumeMetricUnary(resultsObjVectors[i]) << endl;
    }
    cout << "HyperVolume: " << hyperVolumeMetricUnary(optimalFrontObjVector) << endl;



    moeoHyperVolumeDifferenceMetric <SatOptObjectiveVector>hyperVolDiff(true, 1.1);
    cout << "\nBinary Hyper volume is:" << endl;
    //This loop calculates and print the hyperVolumeDiff
    for(int i=0;i<results.size();i++){
        //hyperVolDiff.setup(optimalFrontObjVector,resultsObjVectors[i]);
        cout << "hyperDiff: " << hyperVolDiff(optimalFrontObjVector,resultsObjVectors[i]) << endl;
    }


    moeoVecVsVecAdditiveEpsilonBinaryMetric < SatOptObjectiveVector > additiveEpsilon(true);
    //This loop calculates and print the AdditiveEpsilonBinaryMetric
    for(int i=0;i<results.size();i++){
        //hyperVolDiff.setup(optimalFrontObjVector,resultsObjVectors[i]);
        cout << "additiveEpsilon: " << additiveEpsilon(resultsObjVectors[i],optimalFrontObjVector) << endl;
    }

    moeoEntropyMetric < SatOptObjectiveVector > entropyMetric;
     //This loop calculates and print the entropyMetric
    for(int i=0;i<results.size();i++){
        //by swapping the inputs we will get constant value for all, i don't know why
        cout << "entropyMetric: " << entropyMetric(resultsObjVectors[i],optimalFrontObjVector) << endl;
    }


    return EXIT_SUCCESS;
}


// A main that catches the exceptions

int main(int argc, char **argv) {

    try {
        //std::to_string(5);
        main_function(argc, argv);
    } catch (exception& e) {
        cout << "Exception: " << e.what() << '\n';
    }

    return 0;
}
