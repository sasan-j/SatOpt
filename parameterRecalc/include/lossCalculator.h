#ifndef LOSSCALCULATOR_H
#define LOSSCALCULATOR_H

#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <sstream> //this is where istringstream is defined
#include <fstream>
#include <unordered_map>
#include <assert.h>



class lossCalculator
{
    public:
        /** Default constructor */
        lossCalculator();
        /** Default destructor */
        ~lossCalculator();
        double calculatePathLoss(std::string);
    protected:
    private:
    std::string fileName;
    double switchLoss;
    std::unordered_map<std::string,unsigned int> channels;
    std::vector < std::vector <std::string> > values;
    std::unordered_map<std::string,unsigned int> links;
};

#endif // LOSSCALCULATOR_H
