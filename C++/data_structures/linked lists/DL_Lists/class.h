#ifndef __CLASS_H__
#define __CLASS_H__

#include <iostream>

struct Node
{
    int data;
    Node* next;
    Node* previous;

};

class DL_List
{
    private:
    Node* head;
    public:
    DL_List();
    void addNode(int);
    void printList();
    void revPrint();

};

#endif