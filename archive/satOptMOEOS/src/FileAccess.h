/* 
 * File:   FileAccess.h
 * Author: snjix
 *
 * Created on August 9, 2013, 1:21 PM
 */

#ifndef FILEACCESS_H
#define	FILEACCESS_H

#include <fstream>
#include <string>
#include <iostream>
#include <sstream> //this is where istringstream is defined


class FileAccess {
public:
    FileAccess();
    FileAccess(const FileAccess& orig);
    virtual ~FileAccess();
    void getChanInstance(unsigned int chan_count, unsigned int chan_inst);
    void getSwInstance(unsigned int sw_inst);
private:

};

#endif	/* FILEACCESS_H */

