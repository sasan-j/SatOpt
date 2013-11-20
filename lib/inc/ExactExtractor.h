#ifndef EXACTEXTRACTOR_H
#define EXACTEXTRACTOR_H

#include<vector>
#include<string>
#include<stdio.h>
#include <eo>
#include <ga.h>
#include <moeo>
#include"SatOpt.h"

// exact fron extractor
class ExactExtractor
{
private:
    unsigned int chCount;
    unsigned int swInst;
    unsigned int chInst;
    std::vector<SatOptObjectiveVector> optimalFront;
public:
    ExactExtractor(unsigned int _swInst, unsigned int _chCount ,unsigned int _chInst);
    bool isAvailable();
    std::vector<SatOptObjectiveVector> getExactFront(void);

};

#endif // EXACTEXTRACTOR_H
