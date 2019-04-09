//================================================================
// Author      : Donner Hanson
// Date        : 04/09/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Registrar Queue Analysis
// File Name   : ParseAndRunMetrics.cpp
// Assignment  : Assignment 4
// Version     : 0.0
// Instructor  : Rene German
// Description : Function to run registrar simulation
//================================================================

#include "ParseAndRunMetrics.hpp"

#include <algorithm>
#include <iostream>
#include <fstream>


#include "Error.h"
#include "FileHandler.hpp"
#include "Metrics.hpp"
#include "Queue_Custom.h"
#include "Student.hpp"
#include "Window.hpp"

using namespace std;

void ParseAndRunMetrics::run(string fName)
{
    try {
        ifstream inFileStream;
        FileHandler inFile;
        inFile.SafeOpenForRead(inFileStream, fName);
        CustQueue<int> fileNums = inFile.fileToQueue();
        inFile.Close();
        // student waiting queue
        CustQueue<Student*> sWQ;
        // student exit queue
        CustQueue<Student*> sEQ;
        // array of windows - fileNums.dequeue returns first number in file
        int amountOfWindows = fileNums.dequeue();
        //cout << "amountofwindows: " << amountOfWindows << "\n";
        Window* windows = new Window[amountOfWindows]();
        
        for(int mins(0); true; ++mins)
        {
            // students arriving to the queue (line for registrar)
            if (!fileNums.isEmpty() && mins == fileNums.front())
            {
                // clock tick reached - remove clock tick from queue
                fileNums.dequeue();
                // get number of students to add
                int numNewStuds(fileNums.dequeue()), numInsertedToStudQueue(0);
                while (numInsertedToStudQueue < numNewStuds)
                {
                    // set the next student(time to spend at window)
                    Student* temp = new Student(fileNums.dequeue());
                    sWQ.enqueue(temp);
                    ++numInsertedToStudQueue;
                }
            }
            // IF no more arriving students, student queue is empty
                // and all windows empty
                // DONE FOR THE DAY - Lets EXIT and get results
            if (fileNums.isEmpty() && sWQ.isEmpty() &&
                all_of(windows, windows+amountOfWindows, [](Window w)
                       { return w.hasStudent() == false; }))
            {
                break;
            }
            // loop through windows to see who is free
            for(int windowNum(0); windowNum < amountOfWindows; windowNum++)
            {
                if (windows[windowNum].hasStudent())
                {
                    // increase time at window
                    windows[windowNum].increaseCurrTimeAtWindow();
                    // if student needs to leave free up window
                    // else only the time spent at window will be increased
                    if (windows[windowNum].studentReadyToLeaveWindow())
                    {
                        sEQ.enqueue(windows[windowNum].freeUpWindow());
                        if (!sWQ.isEmpty())
                        {
                            Student *addStudent = sWQ.dequeue();
                            windows[windowNum].setStudent(addStudent);
                        }
                    }
                }
                if (!windows[windowNum].hasStudent())
                {
                    if (!sWQ.isEmpty())
                    {
                        Student *addStudent = sWQ.dequeue();
                        windows[windowNum].setStudent(addStudent);
                    }
                    else if (sWQ.isEmpty())
                    {
                        windows[windowNum].increaseIdle();
                    }
                }
            }
            // increase the time waiting of each student in line
            CustQueue<Student*> studentWaitingQueueIncrease;
            while (!sWQ.isEmpty())
            {
                Student* temp;
                temp = sWQ.dequeue();
                temp->increaseTimeWating();
                studentWaitingQueueIncrease.enqueue(temp);
            }
            // place back in waiting queue
            while(!studentWaitingQueueIncrease.isEmpty())
            {
                sWQ.enqueue(studentWaitingQueueIncrease.dequeue());
            }
        }
        
        int sizeSWT(sEQ.getSize());
        int* studentWaitTimes = new int[sizeSWT];
        for (int numStuds(0); numStuds < sizeSWT; ++numStuds)
        {
            Student* temp = sEQ.dequeue();
            studentWaitTimes[numStuds] = temp->getTimeWaiting();
            // delete the student object
            delete temp;
        }
        
        Metrics metric (studentWaitTimes, sizeSWT, windows, amountOfWindows);
        // OUTPUT RESULTS
        cout << "1. The mean student wait time: "
                << metric.getMeanSWT() << "\n";
        cout << "2. The median student wait time:  "
                << metric.getMedianSWT() << "\n";
        cout << "3. The longest student wait time: "
                << metric.getLongestSWT() << "\n";
        cout << "4. The number of students waiting over 10 minutes: "
                << metric.getTotalSWTOverTenMin() << "\n";
        cout << "5. The mean window idle time "
                << metric.getmeanWindowIdleTime() << "\n";
        cout << "6. The longest window idle time: "
                << metric.getLongestWindowIdleTime() << "\n";
        cout << "7. The number of windows idle over five minutes: "
                << metric.getNumWindowsIdleOverFive() << "\n";
        delete [] studentWaitTimes;
        delete [] windows;
    }
    catch (Error& e)
    {
        throw e;
    }
    catch(...)
    {
        throw Error("Unhandled Exception\n");
    }
}
