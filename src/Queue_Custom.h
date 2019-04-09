//================================================================
// Author      : Donner Hanson
// Date        : 04/09/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Registrar Queue Analysis
// File Name   : Queue_Cust.h
// Assignment  : Assignment 4
// Version     : 0.0
// Instructor  : Rene German
// Description : Template Queue that uses an internal DLL
//================================================================

#ifndef Queue_Custom_h
#define Queue_Custom_h

#include "DLL.h"

template <typename T>
class CustQueue
{
public:
    // default constructor
    CustQueue()
    {
        numElems = 0;
    }
    // destructor
    ~CustQueue(){};
    
    // insert - from back
    void enqueue(T val)
    {
        internalDLList.insertBack(val);
        ++numElems;
    }
    // remove - from front
    T dequeue()
    {
        try
        {
            T val = internalDLList.removeFront();
            --numElems;
            return val;
        }
        catch(...)
        {
            throw;
        }
    }
    
    // peek()
    T front()
    {
        return internalDLList.getFrontData();
    }
    // show back data
    T back()
    {
        return internalDLList.getFrontData();
    }
    bool isFull()
    {
        try
        {
            return false;
        }
        catch(...)
        {
            throw;
        }
    }
    bool isEmpty()
    {
        return internalDLList.isEmpty();
    }
    unsigned int getSize()
    {
        return internalDLList.getSize();
    }
    void printQueue()
    {
        if (getSize() > 0)
        {
            internalDLList.printList();
        }
    }
    
private:
    int numElems;
    DLL<T> internalDLList;
};


#endif /* Queue_Custom_h */
