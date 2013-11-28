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
    double elapsedTime;
    unsigned int genCount;
    moeoUnboundedArchive<SatOpt> finalArchive;
    
    RunResult();
    RunResult(const RunResult& orig);
    virtual ~RunResult();
    RunResult& operator =(const RunResult& _result);
    void setFinalArchiveFromPop(eoPop<SatOpt> _pop);
    void incGenCount();
    void setElapsedTime(double _elapsed);
private:

};

#endif	/* RUNRESULT_H */

