/*
 * File:   SatOptEval.h
 * Author: snjix
 *
 * Created on August 9, 2013, 11:54 AM
 */

#ifndef SATOPTEVAL_H
#define	SATOPTEVAL_H

// evaluation of objective functions

class SatOptEval : public moeoEvalFunc < SatOpt >{
public:
void operator () (SatOpt & _satOpt);
};

#endif	/* SATOPTEVAL_H */