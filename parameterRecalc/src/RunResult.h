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
#include "../satOpt.h"
#include <vector>

class RunResult {
public:
    double elapsedTime;
    unsigned int genCount;
    moeoUnboundedArchive<SatOpt> finalArchive;
    std::string resultFileName;
    std::vector<SatOptObjectiveVector> finalArchiveVector;

    RunResult();
    RunResult(const RunResult& orig);
    virtual ~RunResult();
    RunResult& operator =(const RunResult& _result);
    void setFinalArchiveFromPop(eoPop<SatOpt> _pop);
    void incGenCount();

    void setElapsedTime(double _elapsed);

    double getUnaryHyperVol();
    void setUnaryHyperVol(double);

    double getBinaryHyperVol();
    void setBinaryHyperVol(double);

    double getAdditiveEps();
    void setAdditiveEps(double);

    double getEntropy();
    void setEntropy(double);
private:
    double unaryHyperVol;
    double binaryHyperVol;//diff with true
    double additiveEps;
    double entropy;
};

#endif	/* RUNRESULT_H */

