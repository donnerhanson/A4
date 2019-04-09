//================================================================
// Author      : Donner Hanson
// Date        : 04/09/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Registrar Queue Analysis
// File Name   : Student.cpp
// Assignment  : Assignment 4
// Version     : 0.0
// Instructor  : Rene German
// Description : Functions for class Student
//================================================================

#include "Student.hpp"

int Student::getTimeNeeded()
{
    return timeNeeded;
}
bool Student::isFinished(int timeSpentAtWindow)
{
    // >= depending on if 0 needed or not
    if (timeSpentAtWindow >= timeNeeded)
        return true;
    return false;
}
int Student::getTimeWaiting()
{
    return timeWaiting;
}
void Student::increaseTimeWating()
{
    ++timeWaiting;
}
void Student::setAtWindow(bool b)
{
    atWindow = b;
}

ostream& operator << (ostream& out, const Student &stud)
{
    out << "time waited: " << stud.timeWaiting;
    out << "time needed: " << stud.timeNeeded;
    return out;
}
