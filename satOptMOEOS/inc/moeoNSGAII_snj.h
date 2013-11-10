/* 
 * File:   moeoNSGAII_snj.h
 * Author: snjix
 *
 * Created on August 1, 2013, 11:53 AM
 */

#ifndef MOEONSGAII_SNJ_H
#define	MOEONSGAII_SNJ_H


#include <eoBreed.h>
#include <eoCloneOps.h>
#include <eoContinue.h>
#include <eoEvalFunc.h>
#include <eoGenContinue.h>
#include <eoGeneralBreeder.h>
#include <eoGenOp.h>
#include <eoPopEvalFunc.h>
#include <eoSGAGenOp.h>
#include <algo/moeoEA.h>
#include <diversity/moeoFrontByFrontCrowdingDiversityAssignment.h>
#include <fitness/moeoDominanceDepthFitnessAssignment.h>
#include <replacement/moeoElitistReplacement.h>
#include <selection/moeoDetTournamentSelect.h>

/**
 * NSGA-II (Non-dominated Sorting Genetic Algorithm II).
 * Deb, K., S. Agrawal, A. Pratap, and T. Meyarivan. A fast elitist non-dominated sorting genetic algorithm for multi-objective optimization: NSGA-II. IEEE Transactions on Evolutionary Computation, Vol. 6, No 2, pp 182-197 (2002).
 * This class builds the NSGA-II algorithm only by using the fine-grained components of the ParadisEO-MOEO framework.
 */
template < class MOEOT >
class moeoNSGAII_snj: public moeoEA < MOEOT >
{
public:

    /**
     * Ctor with a crossover, a mutation and their corresponding rates.
     * @param _maxGen maximum number of generations before stopping
     * @param _eval evaluation function
     * @param _crossover crossover
     * @param _pCross crossover probability
     * @param _mutation mutation
     * @param _pMut mutation probability
     */
    moeoNSGAII_snj (unsigned int _maxGen, eoEvalFunc < MOEOT > & _eval, eoQuadOp < MOEOT > & _crossover, double _pCross, eoMonOp < MOEOT > & _mutation, double _pMut) :
            defaultGenContinuator(_maxGen), continuator(defaultGenContinuator), eval(_eval), defaultPopEval(_eval), popEval(defaultPopEval), select (2), selectMany(select,0.0), selectTransform(defaultSelect, defaultTransform), defaultSGAGenOp(_crossover, _pCross, _mutation, _pMut), genBreed (select, defaultSGAGenOp), breed (genBreed), replace (fitnessAssignment, diversityAssignment)
    {}


    /**
     * Ctor with a eoContinue and a eoGenOp.
     * @param _continuator stopping criteria
     * @param _eval evaluation function
     * @param _op variation operators
     */
    moeoNSGAII_snj (eoContinue < MOEOT > & _continuator, eoEvalFunc < MOEOT > & _eval, eoGenOp < MOEOT > & _op) :
            defaultGenContinuator(0), continuator(_continuator), eval(_eval), defaultPopEval(_eval), popEval(defaultPopEval), select(2),
            selectMany(select,0.0), selectTransform(defaultSelect, defaultTransform), defaultSGAGenOp(defaultQuadOp, 1.0, defaultMonOp, 1.0), genBreed(select, _op), breed(genBreed), replace (fitnessAssignment, diversityAssignment)
    {}


    /**
     * Ctor with a eoContinue, a eoPopEval and a eoGenOp.
     * @param _continuator stopping criteria
     * @param _popEval population evaluation function
     * @param _op variation operators
     */
    moeoNSGAII_snj (eoContinue < MOEOT > & _continuator, eoPopEvalFunc < MOEOT > & _popEval, eoGenOp < MOEOT > & _op) :
            defaultGenContinuator(0), continuator(_continuator), eval(defaultEval), defaultPopEval(eval), popEval(_popEval), select(2),
            selectMany(select,0.0), selectTransform(defaultSelect, defaultTransform), defaultSGAGenOp(defaultQuadOp, 1.0, defaultMonOp, 1.0), genBreed(select, _op), breed(genBreed), replace (fitnessAssignment, diversityAssignment)
    {}


    /**
     * Ctor with a eoContinue and a eoTransform.
     * @param _continuator stopping criteria
     * @param _eval evaluation function
     * @param _transform variation operator
     */
    moeoNSGAII_snj (eoContinue < MOEOT > & _continuator, eoEvalFunc < MOEOT > & _eval, eoTransform < MOEOT > & _transform) :
            defaultGenContinuator(0), continuator(_continuator), eval(_eval), defaultPopEval(_eval), popEval(defaultPopEval),
            select(2),  selectMany(select, 1.0), selectTransform(selectMany, _transform), defaultSGAGenOp(defaultQuadOp, 0.0, defaultMonOp, 0.0), genBreed(select, defaultSGAGenOp), breed(selectTransform), replace(fitnessAssignment, diversityAssignment/*, compare*/)
    {}


    /**
     * Ctor with a eoContinue, a eoPopEval and a eoTransform.
     * @param _continuator stopping criteria
     * @param _popEval population evaluation function
     * @param _transform variation operator
     */
    moeoNSGAII_snj (eoContinue < MOEOT > & _continuator, eoPopEvalFunc < MOEOT > & _popEval, eoTransform < MOEOT > & _transform) :
            defaultGenContinuator(0), continuator(_continuator), eval(defaultEval), defaultPopEval(eval), popEval(_popEval),
            select(2),  selectMany(select, 1.0), selectTransform(selectMany, _transform), defaultSGAGenOp(defaultQuadOp, 0.0, defaultMonOp, 0.0), genBreed(select, defaultSGAGenOp), breed(selectTransform), replace(fitnessAssignment, diversityAssignment/*, compare*/)
    {}

/**
     * Apply a the algorithm to the population _pop until the stopping criteria is satified.
     * @param _pop the population
     */
    virtual void operator () (eoPop < MOEOT > &_pop) {

        //moeoUnboundedArchive < MOEOT > _arch;
        //moeoArchiveObjectiveVectorSavingUpdater<MOEOT> archSaver(_arch, "result.txt", false, 0);
        //moeoArchiveUpdater <MOEOT> archUpdater(_arch, _pop);
        //moeoArchive < SatOpt > arch;
        //_arch(_pop);
       // int genCount = 0;
        //double hyp=0;

        eoPop < MOEOT > offspring, empty_pop;
        popEval(empty_pop, _pop); // a first eval of _pop
        // evaluate fitness and diversity
        fitnessAssignment(_pop);
        diversityAssignment(_pop);
        do {    


            // generate offspring, worths are recalculated if necessary
            breed(_pop, offspring);
            // eval of offspring
            popEval(_pop, offspring);
            
            
            //if (0 == genCount % 5) {
                //samplePayload->penaltyCoeff += 1.0f;
                //for(int i=0;i<_pop.size();i++){
                //      eval(_pop[i]);
                //        eval(_pop[i]);
                //}
                //_pop.sortedPrintOn(std::cout);
                // popEval(empty_pop, _pop); // a first eval of _pop
                //_pop.sortedPrintOn(std::cout);
                //popDiversityCalc(_pop);
                //popDiversityCalcByFitness(_pop);
                //fitnessAssignment(_pop);
                //diversityAssignment(_pop);
           // }            
            ///////////////////////////////
            ///////////////////////////////
            // after replace, the new pop is in _pop. Worths are recalculated if necessary
            replace(_pop, offspring);
            // cout << _pop.best_element()<<endl;
            //std::cout << genCount++ << " *** " << _pop.best_element() << std::endl; 
            //_arch(_pop);
            //std::cout << "Switch Changes\tLPL\n";
            //archUpdater();
            //_arch.sortedPrintOn(std::cout);
            //archSaver();

            
            //genCount++;
        }        while (continuator(_pop));
    }

    
    void popDiversityCalcByFitness(eoPop<MOEOT> &_pop){

        
        typename eoPop<MOEOT>::iterator iter1;
        typename eoPop<MOEOT>::iterator iter2;
        
        iter1 = _pop.begin();
        iter2=_pop.begin();
        iter2++;
        int popSize = _pop.size();
        for (; iter1 != _pop.end(); ) {
            //std::cout << "first for\n"; 
            for (iter2=iter1+1; iter2 != _pop.end();) {
                //std::cout << "obj 00 is: " << (*iter1).objectiveVector(0) << " obj 01 is: " << (*iter1).objectiveVector(1) << std::endl;
                if ((*iter1).objectiveVector(0) == (*iter2).objectiveVector(0) &&
                        (*iter1).objectiveVector(1) == (*iter2).objectiveVector(1)) {
                    _pop.erase(iter2);
                } else
                    ++iter2;
            }
            ++iter1;
        }
        
       
        std::cout << "unique indi's are: " << _pop.size() << std::endl;
        //std::cout << "pop size is: " << _pop.size() << std::endl;

        induceNewIndies(_pop,(popSize-_pop.size()));
        std::cout << "new pop size : " << _pop.size() << std::endl;

        
        
    }
    
    
    void popDiversityCalc(eoPop<MOEOT> &_pop){

        
        typename eoPop<MOEOT>::iterator iter1;
        typename eoPop<MOEOT>::iterator iter2;
        iter1=_pop.begin();


        int popSize = _pop.size();
        for (; iter1 != _pop.end();) {
            //MOEOT *temp1 = iter1;
            //std::cout << "first for\n"; 
            for (iter2=iter1+1; iter2 != _pop.end();) {
                //std::cout << "second for\n"; 
               // MOEOT *temp2 = iter2();
                bool same = true;
                for (int k = 0; k < _pop[0].size(); k++) {
                    //std::cout << "third for\n"; 
                    if ((*iter1)[k] != (*iter2)[k]) {
                        same = false;
                        break;
                    }
                }
                if (same) {
                    _pop.erase(iter2);
                }
                else
                    ++iter2;
            }
            ++iter1;
        }
        
       
        std::cout << "unique indi's are: " << _pop.size() << std::endl;
        //std::cout << "pop size is: " << _pop.size() << std::endl;
        
        for(iter1=_pop.begin();iter1!=_pop.end();++iter1){
            (*iter1).invalidate();
            eval(*iter1);
        }
        
        induceNewIndies(_pop,(popSize-_pop.size()));

        std::cout << "new pop size : " << _pop.size() << std::endl;

        
    }

    
    
    void induceNewIndies(eoPop<MOEOT> &_pop, int newIndies) {
        rng.reseed(time(NULL));
        for (unsigned int igeno = 0; igeno < newIndies; igeno++) {
            MOEOT v; // void individual, to be filled
            for (unsigned ivar = 0; ivar < _pop[0].size(); ivar++) {
                bool r = rng.flip(); // new value, random in {0,1}
                v.push_back(r); // append that random value to v
            }
            eval(v); // evaluate it
            //_pop.pop_back();
            _pop.push_back(v); // and put it in the population
        }
    }

protected:

    /** a continuator based on the number of generations (used as default) */
    eoGenContinue < MOEOT > defaultGenContinuator;
    /** stopping criteria */
    eoContinue < MOEOT > & continuator;
    /** default eval */
    class DummyEval : public eoEvalFunc < MOEOT >
    {
    public:
        void operator()(MOEOT &) {}
    }
    defaultEval;
    /** evaluation function */
    eoEvalFunc < MOEOT > & eval;
    /** default popEval */
    eoPopLoopEval < MOEOT > defaultPopEval;
    /** evaluation function used to evaluate the whole population */
    eoPopEvalFunc < MOEOT > & popEval;
    /** default select */
    class DummySelect : public eoSelect < MOEOT >
    {
    public :
        void operator()(const eoPop<MOEOT>&, eoPop<MOEOT>&) {}
    }
    defaultSelect;
    /** binary tournament selection */
    moeoDetTournamentSelect < MOEOT > select;
    /** default select many */
    eoSelectMany < MOEOT >  selectMany;
    /** select transform */
    eoSelectTransform < MOEOT > selectTransform;
    /** a default crossover */
    eoQuadCloneOp < MOEOT > defaultQuadOp;
    /** a default mutation */
    eoMonCloneOp < MOEOT > defaultMonOp;
    /** an object for genetic operators (used as default) */
    eoSGAGenOp < MOEOT > defaultSGAGenOp;
    /** default transform */
    class DummyTransform : public eoTransform < MOEOT >
    {
    public :
        void operator()(eoPop<MOEOT>&) {}
    }
    defaultTransform;
    /** general breeder */
    eoGeneralBreeder < MOEOT > genBreed;
    /** breeder */
    eoBreed < MOEOT > & breed;
    /** fitness assignment used in NSGA */
    moeoDominanceDepthFitnessAssignment < MOEOT > fitnessAssignment;
    /** diversity assignment used in NSGA-II */
    //moeoFrontByFrontSharingDiversityAssignment  < MOEOT > diversityAssignment;
    moeoFrontByFrontCrowdingDiversityAssignment  < MOEOT > diversityAssignment;
    /** elitist replacement */
    moeoElitistReplacement < MOEOT > replace;
    //moeoEnvironmentalReplacement < MOEOT > replace;
    /** comparator snjix*/
    //moeoDiversityThenFitnessComparator < MOEOT > compare;


};

#endif	/* MOEONSGAII_SNJ_H */

