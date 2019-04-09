//================================================================
// Author      : Donner Hanson
// Date        : 04/09/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Registrar Queue Analysis
// File Name   : FileHandler.cpp
// Assignment  : Assignment 4
// Version     : 0.0
// Instructor  : Rene German
// Description : functions to open/close file in read safely
//================================================================

#include <iostream>
#include <fstream>
#include <string>

#include "Queue_Custom.h"
#include "Error.h"
#include "FileHandler.hpp"

using namespace std;

bool FileHandler::SafeOpenForRead(ifstream& inFile, string fileName)
{
    try{
        inFile.open(fileName, ios::in);
        if(inFile.is_open() && !fileIsBlank(inFile))
        {
            // uncomment below to show filename and success during runtime
            //cout << "File: <" << fileName << "> opened successfully...\n";
            file = &inFile;
            return true;
        }
        throw Error ("File Not Found: Exiting...");
        return false;
    }
    catch(Error &e)
    {
        throw e;
    }
}

bool FileHandler::fileIsBlank(ifstream& inFile)
{
    return inFile.peek() == ifstream::traits_type::eof();
}

bool FileHandler::isNotWS(const string &str)
{
    return str.find_first_not_of(' ') != string::npos;
}

void FileHandler::Close()
{
    file->close();
}

CustQueue<int> FileHandler::fileToQueue()
{
    CustQueue<int> temp;
    while (*file >> a)
    {
        temp.enqueue(a);
    }
    return temp;
}

