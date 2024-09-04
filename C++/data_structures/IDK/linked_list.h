#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <iostream>
#include "interface.h"



class List : public IData
{
private:
    Node_t *head;
    void deleteByValue(int);
    void eraseLastNode();

public:
    List();

    void addNode(int) override;
    void print() override;
    bool isContains(int) override;
};

#endif