//================================================================
// Author      : Donner Hanson
// Date        : 04/09/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Registrar Queue Analysis
// File Name   : Window.cpp
// Assignment  : Assignment 4
// Version     : 0.0
// Instructor  : Rene German
// Description : Functions for class Window that calculate idle times as well
//               as the max and total student wait times to get to the window
//================================================================


#include "Window.hpp"

#include "Student.hpp"

bool Window::studentReadyToLeaveWindow()
{
    if (student->isFinished(currTimeAtWindow))
    {
        return true;
    }
    return false;
}
// get student time waiting - obtain ownership of student object
void Window::setStudent(Student* stud)
{
    student = stud;
    student->setAtWindow(true);
    setStudentAtWindow(true);
    currTimeAtWindow = 0;
    totalSWT += stud->getTimeWaiting();
    if (stud->getTimeWaiting() > longestSWT)
    {
        longestSWT = stud->getTimeWaiting();
    }
    if (stud->getTimeWaiting() > 10)
    {
        ++overTenMinsSWT;
    }
}
int Window::getStudentTimeWaiting()
{
    return totalSWT;
}
int Window::getTotalIdleTime()
{
    return totalIdleTime;
}
int Window::getSWTOverTen()
{
    return overTenMinsSWT;
}
int Window::getLongestSWT()
{
    return longestSWT;
}
void Window::increaseIdle()
{
    currIdleTime++;
    totalIdleTime++;
    if (currIdleTime > 5)
    {
        wasIdleOverFive = true;
    }
}
void Window::increaseCurrTimeAtWindow()
{
    ++currTimeAtWindow;
}
Student* Window::freeUpWindow()
{
    setStudentAtWindow(false);
    currTimeAtWindow = 0;
    if (currIdleTime > longestIdleTime)
        longestIdleTime = currIdleTime;
    currIdleTime = 0;
    return student;
}
int Window::getCurrTimeAtWindow()
{
    return currTimeAtWindow;
}
void Window::setStudentAtWindow(bool b)
{
    studentAtWindow = b;
}
bool Window::hasStudent()
{
    return studentAtWindow;
}
Student Window::getStudentInfo()
{
    return *student;
}
int Window::getLongestIdleTime()
{
    return longestIdleTime;
}
bool Window::getWasIdleOverFive()
{
    return wasIdleOverFive;
}
