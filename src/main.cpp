//================================================================
// Author      : Donner Hanson
// Date        : 04/09/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Registrar Queue Analysis
// File Name   : main.cpp
// Assignment  : Assignment 4
// Version     : 0.0
// Instructor  : Rene German
// Description : run parse and metric calculations of simulated registrar wait
//               and idle times
//================================================================

#include <algorithm>
#include <iostream>
#include <fstream>


#include "Error.h"
#include "ParseAndRunMetrics.hpp"


using namespace std;
// need txt argument
int main(int argc, const char * argv[]) {
    try
    {
        if (argc <= 1)
        {
            throw Error("not enough arguements");
        }
        if (argc > 2)
        {
            throw Error("too many arguments");
        }
        ParseAndRunMetrics().run(string(argv[1]));
    }
    catch(Error& e)
    {
        cout << e.what() << "\n";
    }
    catch(...)
    {
        cout << "Unhandled exception";
    }
    return 0;
}
