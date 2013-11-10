/*
 * File:   FileAccess.cpp
 * Author: snjix
 *
 * Created on August 9, 2013, 1:21 PM
 */

#include "FileAccess.h"

FileAccess::FileAccess() {
}

FileAccess::FileAccess(const FileAccess& orig) {
}

FileAccess::~FileAccess() {
}

void FileAccess::getChanInstance(unsigned int chan_count, unsigned int chan_inst){
    //std::ifstream infile("thefile.txt");
    //std::string fileName="ref/chan_inst_"+std::to_string(chan_inst)+".txt";
    std::string fileName="ref/chan_inst_8.txt";
    std::ifstream infile(fileName.c_str());
    std::string line;
    for(int i=0;i<chan_inst;i++)
    {
        std::getline(infile, line);
        std::istringstream iss(line);
        std::string  a, b, c;
        if (!(iss >> a >> b >> c)) { break; } // error
        std::cout << a << "  " << b << "  " << c << std::endl;
        // process pair (a,b)
    }



}
void FileAccess::getSwInstance(unsigned int sw_inst){

}
