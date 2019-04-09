//================================================================
// Author      : Donner Hanson
// Date        : 04/09/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Registrar Queue Analysis
// File Name   : DLL.h
// Assignment  : Assignment 4
// Version     : 0.0
// Instructor  : Rene German
// Description : Doubly linked list generic template
//================================================================

#ifndef DLL_h
#define DLL_h

#include <iostream>

template <typename U>
class Node{
public:
    // default constructor
    // set ptr to NULL/nullptr/0
    Node(): data(0), next(NULL), prev (NULL){};
    Node(U value): data(value), next(0), prev(0){}; // overloaded
    ~Node()
    {
        prev = nullptr;
        next = nullptr;
        delete next;
    }
    Node<U> *next, *prev;
    U getData()
    {
        return data;
    }
private:
    U data;
};
template <typename U>
class DLL{
public:
    DLL() : size(0), front(nullptr), back(nullptr){};
    ~DLL()
    {
        Node<U>* current = front;
        while( current != nullptr )
        {
            current->prev = nullptr;
            Node<U>* next = current->next;
            delete current;
            --size;
            current = next;
        }
        front = nullptr;
    }
    void insertFront(U data)
    {
        Node<U>* node = new Node<U>(data);
        
        if(isEmpty())
        {
            back = node;
        }
        else
        {
            node->next = front;
            front->prev = node;
        }
        front = node;
        size++;
    }
    U removeFront()
    {
        U temp = getFrontData();
        Node<U>* node = front;
        if (isEmpty())
        {
            try{
            back = nullptr;
            }
            catch(...)
            {
                throw;
            }
            
            // throw exception
        }
        else if (front->next == nullptr)
        {
            front = nullptr;
        }
        else
        {
            
            front->next->prev = nullptr;
            
        }
        if(front != nullptr)
            front = front->next;
        node->next = nullptr;
        delete node;
        size--;
        return temp;
    }
    
    void insertBack(U data)
    {
        Node<U>* node = new Node<U>(data);
        
        if(isEmpty())
        {
            front = node;
        }
        else
        {
            back->next = node;
            node->prev = back;
            
        }
        back = node;
        size++;
    }
    
    /* REMOVE BACK HERE */
    
    U removeKey(U key)
    {
        // could use find() here
        
        Node<U>* curr = front;
        
        // look for val
        while (curr->getData()!=key)
        {
            curr = curr->next;
            if (curr == nullptr)
                return NULL;
        }
        if (curr == front) // front Node
        {
            front = curr->next;
            
        }
        else
        {
            // is in middle or back
            curr->prev->next = curr->next;
        }
        if (curr == back)
        {
            back = curr->prev;
        }
        else
        {
            curr->next->prev = curr -> prev;
        }
        curr->next = nullptr;
        curr->prev = nullptr;
        U temp = curr->getData();
        delete curr;
        size--;
        return temp;
    }
    
    
    U deletePos(int pos)
    {
        // assumes the value is known
        if (pos > 0)
        {
            int idx = 0;
            Node<U>* curr = front;
            Node<U>* prev = front;
            while (idx != pos)
            {
                prev = curr; // hangs back
                curr = curr->next;
                ++idx;
            }
            if(idx == pos)
            {
                prev->next = curr->next;
                curr->next = nullptr;
            }
            U temp = curr->getData();
            if(idx == pos)
            {
                delete curr;
                size--;
            }
            return temp;
        }
        else
        {
            if (front == nullptr || front->next == nullptr)
                return NULL;
            else
            {
                // Move the head pointer to the next node
                Node<U> *temp = front;
                front = front->next;
                delete temp;
                size--;
                return front->getData();
            }
        }
    }
    void printList()
    {
        Node<U>* curr = front;
        while (curr)
        {
            std::cout << *curr->getData() << "\n";
            curr = curr->next;
        }
    }
    // return position of data
    int findData(U val)
    {
        int idx = -1;
        Node<U> *curr = front;
        while (curr != nullptr)
        {
            ++idx;
            if (curr->getData() == val)
            {
                break;
            }
            else
            {
                curr = curr->next;
            }
        }
        if (curr == nullptr)
            idx = -1;
        return idx;
    }
    U getFrontData()
    {
        return front->getData();
    }
    U getBackData()
    {
        return back->getData();
    }
    bool isEmpty(){return size <= 0;}
    unsigned int getSize(){return size;}
private:
    Node<U>* back;
    Node<U>* front;
    unsigned int size;
};

#endif /* DLL_h */
