/* 
 * File:   CTimer.cpp
 * Author: snjix
 * 
 * Created on August 7, 2013, 5:20 PM
 */



#include "CTimer.h"	

CTimer::CTimer()
{
	QueryPerformanceFrequency(&mqFreq);
}

void CTimer::Start() 
{
	QueryPerformanceCounter(&mqStart);
}

void CTimer::End() 
{
	QueryPerformanceCounter(&mqEnd);
}

double CTimer::GetTimeInSeconds() 
{
	return (mqEnd.QuadPart - mqStart.QuadPart)/(double)mqFreq.QuadPart;
}

double  CTimer::GetTimeInMilliseconds() 
{
	return (1.0e3*(mqEnd.QuadPart - mqStart.QuadPart))/mqFreq.QuadPart;
}

double CTimer::GetTimeInMicroseconds() 
{
	return (1.0e6*(mqEnd.QuadPart - mqStart.QuadPart))/mqFreq.QuadPart;
}

double CTimer::GetTimeInNanoseconds() 
{
	return (1.0e9*(mqEnd.QuadPart - mqStart.QuadPart))/mqFreq.QuadPart;
}

