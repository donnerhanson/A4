//================================================================
// Author      : Donner Hanson
// Date        : 04/09/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Registrar Queue Analysis
// File Name   : Student.hpp
// Assignment  : Assignment 4
// Version     : 0.0
// Instructor  : Rene German
// Description : Interface for class Student
//================================================================

#ifndef Student_hpp
#define Student_hpp

#include <iostream>
#include <stdio.h>

using namespace std;
class Student
{
    friend ostream& operator << (ostream& out, const Student& stud);
public:
    // empty constructor
    Student() : timeNeeded(0), atWindow(false), timeWaiting(0){};
    // parameter constructor
    Student(int timeNeeded) : timeNeeded(timeNeeded), atWindow(false), timeWaiting(0){};
    // assignment operator
    void operator = (const Student &stud)
    {
        atWindow = stud.atWindow;
        timeNeeded = stud.timeNeeded;
        timeWaiting = stud.timeWaiting;
    }
    int getTimeNeeded();
    bool isFinished(int timeSpentAtWindow);
    int getTimeWaiting();
    void increaseTimeWating();
    void setAtWindow(bool b);
private:
    bool atWindow;
    int timeNeeded;
    int timeWaiting;
};
ostream& operator << (ostream& out, const Student& stud);
#endif /* Student_hpp */
