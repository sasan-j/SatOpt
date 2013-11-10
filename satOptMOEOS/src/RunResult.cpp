/* 
 * File:   RunResult.cpp
 * Author: snjix
 * 
 * Created on August 9, 2013, 11:54 AM
 */

#include "RunResult.h"

RunResult::RunResult() {
    this->elapsedTime = 0;
    this->genCount = 0;
}

RunResult::RunResult(const RunResult& orig) {
    this->elapsedTime = orig.elapsedTime;
    this->genCount = orig.genCount;
    this->finalArchive(orig.finalArchive);
}

RunResult& RunResult:: operator=(const RunResult &_result) {
    this->elapsedTime = _result.elapsedTime;
    this->genCount = _result.genCount;
    this->finalArchive(_result.finalArchive);

    return *this;
}

RunResult::~RunResult() {
}

void RunResult::setFinalArchiveFromPop(eoPop<SatOpt> _pop) {
    this->finalArchive(_pop);
}

void RunResult::incGenCount() {
    this->genCount++;
}

void RunResult::setElapsedTime(double _elapsed) {
    this->elapsedTime = _elapsed;
}
