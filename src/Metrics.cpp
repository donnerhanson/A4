//================================================================
// Author      : Donner Hanson
// Date        : 04/09/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Registrar Queue Analysis
// File Name   : Metrics.cpp
// Assignment  : Assignment 4
// Version     : 0.0
// Instructor  : Rene German
// Description : functions for class Metrics that calculates various analyses
//               of student wait times and window idle times
//================================================================

#include "Metrics.hpp"

#include "Queue_Custom.h"
#include "Student.hpp"
#include "Window.hpp"


// Returns the Mean Student Wait Time
float Metrics::getMeanSWT()
{
    meanSWT = 0;
    for (int i(0); i < sizeOfStudentWaitTimes; ++i)
    {
        meanSWT += studentWaitTimes[i];
    }
    meanSWT /= (sizeOfStudentWaitTimes);
    return meanSWT;
}

// Returns the Median Student Wait Time
float Metrics::getMedianSWT()
{
    // check for odd case - return middle number
    if ((sizeOfStudentWaitTimes - 1) % 2 != 0)
        medianSWT = (float)studentWaitTimes[sizeOfStudentWaitTimes/2];
    // else the median is the mean of the 2 middle most numbers
    else
        medianSWT = (float)(studentWaitTimes[(sizeOfStudentWaitTimes-1)/2] + studentWaitTimes[(sizeOfStudentWaitTimes-1/2)-1])/2.0;
    return medianSWT;
}

// Returns the Longest Student Wait time
int Metrics::getLongestSWT()
{
    
    for (int i(0); i < sizeOfWindowArr; ++i)
    {
        if (windowArr[i].getLongestSWT() > longestSWT)
        {
            longestSWT = windowArr[i].getLongestSWT();
        }
    }
    return longestSWT;
    
}

// Get the total Students that waited over ten mins at each window
int Metrics::getTotalSWTOverTenMin()
{
    totalSWTOverTenMin = 0;
    for (int i(0); i < sizeOfWindowArr; ++i)
    {
        if (windowArr[i].getSWTOverTen() > 0)
        {
            totalSWTOverTenMin += windowArr[i].getSWTOverTen();
        }
    }
    return totalSWTOverTenMin;
}

// Return the mean idle window time
float Metrics::getmeanWindowIdleTime()
{
    meanWindowIdle = 0;
    if (sizeOfWindowArr > 1)
    {
        for (int i(0); i < sizeOfWindowArr; ++i)
        {
            meanWindowIdle = (float)windowArr[i].getTotalIdleTime();
        }
        meanWindowIdle /= (sizeOfWindowArr-1);
    }
    else
    {
        meanWindowIdle = (float)windowArr[0].getTotalIdleTime();
    }
    
    return meanWindowIdle;
}
// Return the longest window idle time - cumalative and non
int Metrics::getLongestWindowIdleTime()
{
    longestWindowIdle = 0;
    for (int i(0); i < sizeOfWindowArr; ++i)
    {
        //NON-Cumalative Idletime
        /*
        if (longestWindowIdle < windowArr[i].getLongestIdleTime())
            longestWindowIdle = windowArr[i].getLongestIdleTime();
         */
        // Cumalative Idletime
        if (longestWindowIdle < windowArr[i].getTotalIdleTime())
            longestWindowIdle = windowArr[i].getTotalIdleTime();
    }
    
    return longestWindowIdle;
}

// Return Number of Windows idle for a 5 min time period
int Metrics::getNumWindowsIdleOverFive()
{
    int numWindowsIdleOverFiveMin = 0;
    for (int i(0); i < sizeOfWindowArr; ++i)
    {
        if (windowArr[i].getWasIdleOverFive())
        {
            ++numWindowsIdleOverFiveMin;
        }
    }
    return numWindowsIdleOverFiveMin;
}

// sort the internal array for calculation of the meduan SWT
void Metrics::sortSWTArr()
{
    int temp;
    for(int i(0); i < sizeOfStudentWaitTimes; ++i)
    {
        for(int j(i + 1); j < sizeOfStudentWaitTimes; ++j)
        {
            if(studentWaitTimes[i]>studentWaitTimes[j])
            {
                temp  = studentWaitTimes[i];
                studentWaitTimes [i] = studentWaitTimes[j];
                studentWaitTimes[j] = temp;
            }
        }
    }
}
