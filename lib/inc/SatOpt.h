/* 
 * File:   SatOpt.h
 * Author: snjix
 *
 * Created on August 9, 2013, 12:17 PM
 */

#ifndef SATOPT_H
#define	SATOPT_H

enum ALGO {NSGA2,SPEA2,IBEA,MOGA};
// the moeoObjectiveVectorTraits : minimizing 2 objectives

class SatOptObjectiveVectorTraits : public moeoObjectiveVectorTraits {
public:

    static bool minimizing(int i) {
        /*if(i==2)
            return false;
        else*/
        return true;
    }

    static bool maximizing(int i) {
        /*if(i==2)
            return true;
        else*/
        return false;
    }

    static unsigned int nObjectives() {
        return 2;
    }
};


// objective vector of real values
typedef moeoRealObjectiveVector < SatOptObjectiveVectorTraits > SatOptObjectiveVector;




// multi-objective evolving object for the SatOpt problem

class SatOpt : public moeoBitVector < SatOptObjectiveVector > {
public:

    SatOpt() : moeoBitVector < SatOptObjectiveVector > (0) {
    }
};

#endif	/* SATOPT_H */

