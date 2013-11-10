/*
 * File:   PrIns.cpp
 * Author: sasan
 *
 * Created on March 28, 2013, 6:09 PM
 */

#include "PrIns.h"

using namespace std;

PrIns::PrIns(string name)
{
    this->problem_instance = name;
}

/*
PrIns::PrIns(const PrIns& orig) {
}
 */
PrIns::~PrIns()
{
}

void PrIns::parseProblem(string problem)
{

    string z = "";
    //char c;
    string k = "";

    vector<string> tmp_chan_instance; //this works, says which channel should connect to amp
    //this for interprets the input string into problem instance
    for (string::size_type i = 1; i < (problem.length()-1); i++)
    {
        char c = problem[i];
        if (c == ',')
        {
            tmp_chan_instance.push_back(z);
            z = "";
        }
        else
        {
            z = z + c;
        }
    }
    tmp_chan_instance.push_back(z);
    this->chan_instance = tmp_chan_instance;
}

void PrIns::setName(string newname)
{
    this->problem_instance = newname;
    this->parseProblem(newname);
}

string PrIns::getName()
{
    return this->problem_instance;
}

void PrIns::setInitSwitchPos(vector<int>& pPos)
{
    this->initSwitchPos.clear();
    for (vector<int>::size_type i = 0; i < pPos.size(); i++)
        this->initSwitchPos.push_back(pPos[i]);
}

vector<int>& PrIns::getInitSwitchPos()
{
    return initSwitchPos;
}

vector<string> PrIns::getChannels() const
{
    return this->chan_instance;
}

void PrIns::setChannels(vector<string> chann)
{
    this->chan_instance = chann;
}

unsigned int PrIns::getVectorSize()
{
    return this->vector_size;
}
void PrIns::setVectorSize(unsigned int _vector_size)
{
    this->vector_size = _vector_size;
}

unsigned int PrIns::getPopSize()
{
    return this->pop_size;
}
void PrIns::setPopSize(unsigned int _pop_size)
{
    this->pop_size = _pop_size;
}

unsigned int PrIns::getMaxTime()
{
    return this->max_time;
}
void PrIns::setMaxTime(unsigned int _max_time)
{
    this->max_time = _max_time;
}
unsigned int PrIns::getIdleGen()
{
    return this->idle_gen;
}
void PrIns::setIdleGen(unsigned int _idle_gen)
{
    this->idle_gen = _idle_gen;
}
unsigned int PrIns::getMinGen()
{
    return this->min_gen;
}
void PrIns::setMinGen(unsigned int _min_gen)
{
    this->min_gen = _min_gen;
}
unsigned int PrIns::getMaxGen()
{
    return this->max_gen;
}
void PrIns::setMaxGen(unsigned int _max_gen)
{
    this->max_gen = _max_gen;
}

double PrIns::getProbMut()
{
    return this->prob_mut;
}
void PrIns::setProbMut(double _prob_mut)
{
    this->prob_mut = _prob_mut;
}

unsigned int PrIns::getSwCount()
{
    return this->sw_count;
}
void PrIns::setSwCount(unsigned int _sw_count)
{
    this->sw_count = _sw_count;
}

