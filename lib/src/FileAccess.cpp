/*
 * File:   FileAccess.cpp
 * Author: snjix
 *
 * Created on August 9, 2013, 1:21 PM
 */

#include "../inc/FileAccess.h"
#include <assert.h>

FileAccess::FileAccess() {
}

FileAccess::FileAccess(const FileAccess& orig) {
}

FileAccess::~FileAccess() {
}

std::vector<std::string> FileAccess::getChanInstance(unsigned int chan_count, unsigned int chan_inst){
    std::string fileName="ref/chan_inst_"+std::to_string(chan_count)+".txt";
    //std::cout << "file name is "<< fileName << std::endl;
    std::ifstream infile(fileName.c_str());
    std::string line;
    std::string  a, b, c;
    for(unsigned int i=0;i<=chan_inst;i++)
    {
        //std::cout << fileName.c_str() << std::endl;
        std::getline(infile, line);
        //std::cout << line << std::endl;
        std::istringstream iss(line);
        if (!(iss >> a >> b >> c)) { break; } // error
        //std::cout << a << "  " << b << "  " << c << std::endl;
        if(i==chan_inst){
            std::vector<std::string> instance;
            instance.push_back(a);
            instance.push_back(c);
            return instance;
        }

    }
    std::vector<std::string> instance;
    return instance;
}
std::vector<std::string> FileAccess::getSwInstance(unsigned int sw_count, int sw_inst){
    std::string fileName="ref/init_sw_pos_"+std::to_string(sw_count)+".txt";
    std::ifstream infile(fileName.c_str());
    std::string line;
    std::string  a, b, c;
    for(int i=0;i<=sw_inst;i++)
    {
        std::getline(infile, line);
        std::istringstream iss(line);
        if (!(iss >> a >> b >> c)) { break; } // error
        //std::cout << a << "  " << b << "  " << c << std::endl;
        if(i==sw_inst){
            std::vector<std::string> instance;
            instance.push_back(a);
            instance.push_back(c);
            return instance;
        }

    }
    std::vector<std::string> instance;
    return instance;
}
