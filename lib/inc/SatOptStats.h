/* 
 * File:   SatOptStats.h
 * Author: snjix
 *
 * Created on August 9, 2013, 12:17 PM
 */

#ifndef SATOPTSTATS_H
#define	SATOPTSTATS_H


#include <string>
#include <vector>
#include "RunResult.h"
#include "ExactExtractor.h"
#include "SatOptEval.h"

class SatOptStats : public moeoObjVecStat<SatOpt >
{
    string str;
    SatOptEval eval;
    RunResult *currentResult;
    string resultDir;

    moeoUnboundedArchive < SatOpt > arch;
    std::vector < std::vector<double> >frontVector;
    unsigned int genCount;
public:
    ALGO algo;

    SatOptStats(string _str) : moeoObjVecStat <SatOpt > ()
    {
	resultDir = _str;
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
};

#endif	/* SATOPTSTATS_H */
