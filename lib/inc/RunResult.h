/*
 * File:   RunResult.h
 * Author: snjix
 *
 * Created on August 9, 2013, 11:54 AM
 */

#ifndef RUNRESULT_H
#define	RUNRESULT_H

#include <eo>
#include <moeo>
#include "SatOpt.h"

class RunResult {
public:

    moeoUnboundedArchive<SatOpt> finalArchive;
    std::string resultFileName;

    RunResult();
    RunResult(const RunResult& orig);
    virtual ~RunResult();
    RunResult& operator =(const RunResult& _result);
    void setFinalArchiveFromPop(eoPop<SatOpt> _pop);
    void incGenCount();

    void setElapsedTime(double _elapsed);
    double getElapsedTime();
    
    void setGenCount(unsigned int);
    unsigned int getGenCount();

    double getUnaryHyperVol();
    void setUnaryHyperVol(double);

    double getBinaryHyperVol();
    void setBinaryHyperVol(double);

    double getAdditiveEps();
    void setAdditiveEps(double);

    double getEntropy();
    void setEntropy(double);
private:
    double elapsedTime;
    unsigned int genCount;
    double unaryHyperVol;
    double binaryHyperVol;//diff with optimal
    double additiveEps;
    double entropy;
};

#endif	/* RUNRESULT_H */

