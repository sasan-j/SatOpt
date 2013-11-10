/* 
 * File:   PrIns.h
 * Author: sasan
 *
 * Created on March 28, 2013, 6:09 PM
 */

#ifndef PRINS_H
#define	PRINS_H


#include <iostream>
#include <vector>

using namespace std;
        

class PrIns {
    std::string problem_instance;
    std::vector<int> initSwitchPos;
    std::vector<std::string> chan_instance; //channels that we want to connect
    unsigned int vector_size;
    unsigned int pop_size;
    unsigned int min_gen;
    unsigned int idle_gen;
    unsigned int max_time;
    unsigned int max_gen;
    double prob_mut;
    /*this method parse the input and updates the instance name*/
    void parseProblem(string problem);

public:
    PrIns(std::string name);
    PrIns(const PrIns& orig);
    virtual ~PrIns();
    void setName(std::string newname);
    std::string getName();

    std::vector<std::string> getChannels() const;
    void setChannels(std::vector<std::string> chann);


    std::vector<int>& getInitSwitchPos();
    void setInitSwitchPos(std::vector<int>& initSwitchPos);
    
    unsigned int getVectorSize();
    void setVectorSize(unsigned int);
    
    unsigned int getPopSize();
    void setPopSize(unsigned int);
    
        
    unsigned int getMaxGen();
    void setMaxGen(unsigned int);
    
        
    unsigned int getMinGen();
    void setMinGen(unsigned int);
    
        
    unsigned int getIdleGen();
    void setIdleGen(unsigned int);
    
        
    unsigned int getMaxTime();
    void setMaxTime(unsigned int);
    
    double getProbMut();
    void setProbMut(double);
    
};

#endif	/* PRINS_H */

