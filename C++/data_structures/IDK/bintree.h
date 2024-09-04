#ifndef __BINTREE__
#define __BINTREE__

#include <iostream>
#include "interface.h"



class Bin_tree : public IData
{
private:
    Node_t *head;
    void addNode(int, Node_t *);
    void print(Node_t *);
    bool contains(Node_t *, int);

public:
    Bin_tree();
    void addNode(int) override;
    void print() override;
    bool isContains(int) override;
};

#endif