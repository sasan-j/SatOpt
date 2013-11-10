/*
 * File:   CTimer.h
 * Author: snjix
 *
 * Created on August 7, 2013, 5:20 PM
 */
#ifndef CTIMER_H
#define CTIMER_H

#include <iostream>
#include <windows.h>
#include <winnt.h>

typedef unsigned long long LARGE_INTEGER;


class CTimer
{
public:
	CTimer();
	void Start();
	void End();
	double GetTimeInSeconds();
	double GetTimeInMilliseconds();
	double GetTimeInMicroseconds();
	double GetTimeInNanoseconds();

private:
	LARGE_INTEGER mqStart;
	LARGE_INTEGER mqEnd;
	LARGE_INTEGER mqFreq;
};

#endif


