//================================================================
// Author      : Donner Hanson
// Date        : 04/09/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Registrar Queue Analysis
// File Name   : Metrics.hpp
// Assignment  : Assignment 4
// Version     : 0.0
// Instructor  : Rene German
// Description : interface for class Metrics that calculates various analyses
//               of student wait times and window idle times
//================================================================

#ifndef Metrics_hpp
#define Metrics_hpp

#include <algorithm>
#include <iostream>
#include <stdio.h>

#include "Queue_Custom.h"
#include "Student.hpp"
#include "Window.hpp"

using namespace std;

class Metrics{
public:
    Metrics (int *studentWaitTimesin, int sizeOfStudentWaitTimes, Window* windowArrin, int sizeOfWindowArr) : meanSWT(0), medianSWT(0), longestSWT(0), totalSWTOverTenMin(0), meanWindowIdle(0), longestWindowIdle(0), numWindowsIdleOverFiveMin(0), sizeOfStudentWaitTimes(sizeOfStudentWaitTimes)
    {
        studentWaitTimes = new int[sizeOfStudentWaitTimes];
        copy(studentWaitTimesin, studentWaitTimesin+sizeOfStudentWaitTimes, studentWaitTimes);
        sortSWTArr();
        this->sizeOfWindowArr = sizeOfWindowArr;
        windowArr = new Window[sizeOfWindowArr];
        copy(windowArrin, windowArrin + sizeOfWindowArr, windowArr);
    }
    
    ~Metrics()
    {
        delete [] studentWaitTimes;
        delete [] windowArr;
    }
    
    float getMeanSWT();
    float getMedianSWT();
    int getLongestSWT();
    int getTotalSWTOverTenMin();
    float getmeanWindowIdleTime();
    int getLongestWindowIdleTime();
    int getNumWindowsIdleOverFive();
    void sortSWTArr();

private:
    int* studentWaitTimes;
    Window* windowArr;
    int sizeOfWindowArr;
    int sizeOfStudentWaitTimes;
    float meanSWT;
    float medianSWT;
    int longestSWT;
    int totalSWTOverTenMin;
    float meanWindowIdle;
    int longestWindowIdle;
    int numWindowsIdleOverFiveMin;
};

#endif /* Metrics_hpp */
