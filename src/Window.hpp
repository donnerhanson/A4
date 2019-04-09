//================================================================
// Author      : Donner Hanson
// Date        : 04/09/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Registrar Queue Analysis
// File Name   : Window.hpp
// Assignment  : Assignment 4
// Version     : 0.0
// Instructor  : Rene German
// Description : Interface for class Window
//================================================================

#ifndef Window_hpp
#define Window_hpp

#include <stdio.h>

#include "Student.hpp"

class Window{
public:
    Window() : totalIdleTime(0), longestIdleTime(0), currIdleTime(0),totalSWT(0), overTenMinsSWT(0), longestSWT(0), currTimeAtWindow(0), studentAtWindow(false), wasIdleOverFive(false){};
    
    bool studentReadyToLeaveWindow();
    // get student time waiting - obtain ownership of student object
    void setStudent(Student* stud);
    int getStudentTimeWaiting();
    int getTotalIdleTime();
    int getSWTOverTen();
    int getLongestSWT();
    void increaseIdle();
    void increaseCurrTimeAtWindow();
    Student* freeUpWindow();
    int getCurrTimeAtWindow();
    void setStudentAtWindow(bool b);
    bool hasStudent();
    Student getStudentInfo();
    int getLongestIdleTime();
    bool getWasIdleOverFive();
private:
    Student* student;
    int totalIdleTime;
    int currIdleTime;
    int longestIdleTime; // non-cumalative idle time
    int totalSWT;
    int overTenMinsSWT;
    int longestSWT;
    int currTimeAtWindow;
    bool studentAtWindow;
    bool wasIdleOverFive;
};


#endif /* Window_hpp */
