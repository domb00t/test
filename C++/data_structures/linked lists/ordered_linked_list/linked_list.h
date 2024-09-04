#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <iostream>
struct Node_t
{
    int data;
    Node_t *next;
};

class List
{
private:
    Node_t *head;
    void deleteByValue(int);
    void eraseLastNode();
    void deleteList(Node_t *);
    void sort();

public:
    List();
    void addNode(int);
    void print();
    bool isContains(int);
    ~List();
};

#endif