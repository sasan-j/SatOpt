/*
 * File:   MyException
 * Author: snjix
 *
 * Created on August 9, 2013, 11:54 AM
 */

#ifndef MYEXCEPTION_H
#define	MYEXCEPTION_H

class MyException:public exception
{
public:
    MyException(const string m)
    {
        msg=m;
    }
    //~MyException(void);
    const char* what()
    {
        return msg.c_str();
    }
private:
    string msg;
};

#endif	/* MYEXCEPTION_H */
