/*
* File:   main.cpp
* Author: sasan
*
* Created on March 28, 2013, 2:40 PM
*/

#define DEBUG_PAYLOAD 1

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
#include "../../lib/inc/Node.h"
#include "../../lib/inc/Port.h"
#include "../../lib/inc/PrIns.h"
#include "../../lib/inc/Payload.h"
#include "../../lib/inc/eoBitOp_.h"
#include "../../lib/inc/moeoNSGAII_snj.h"
#include <time.h>       /* time */
#include <ctime>
#include <string>
#include <chrono>
//#include "../../lib/inc/CTimer.h"
#include "../../lib/inc/SatOpt.h"
#include "../../lib/inc/RunResult.h"
#include "../../lib/inc/FileAccess.h"
#include "../../lib/inc/Payload_100.h"
#include "../../lib/inc/MyException.h"
#include "../../lib/inc/ExactExtractor.h"
//#include "../../lib/inc/SatOptEval.h"
#include "../../lib/inc/SatExperiments.h"
#include "../../lib/inc/SatOptStats.h"


//for getExact
#include <fstream>
#include <iostream>
#include <sstream> //this is where istringstream is defined
#include <vector>

//#define DEBUG_ALL

using namespace std;



//samplePayload.Payload();
PrIns *p1 = new PrIns("initial");
Payload *samplePayload= new Payload(true);
Payload_100 *payloadObject100 = new Payload_100;
vector<int> initSwitchPos;
vector<string> chan_instance; //says which channel should connect to amp
string resultDir = "result/";


// evaluation of objective functions

    void SatOptEval::operator () (SatOpt & _satOpt)
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
    
    SatExperiment* se= new SatExperiment(p1,chCount, swInst, chInst, runs, resultDir);
    
    se->runExperiments();
    //cout << "finish running experiments\n";
    se->validateResults();
    //cout << "validated results\n";
    //se->extractExactOrTrueFron();
    se->extractTrueFront();
    //cout << "extracted true front\n";
    se->extractObjVectors();
    //cout << "extracted objective vectors\n";
    se->calculateBounds();
    //cout << "calculated bounds\n";
    se->calculateMetrics();
    //cout << "calculated metrics\n";

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

