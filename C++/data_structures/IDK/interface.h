#ifndef __INTREFACE__
#define __INTREFACE__

class IData
{
    public:
    virtual void print() =0;
    virtual bool isContains(int) =0;
    virtual void addNode(int)  =0;
};

struct Node_t
{
    int data;
    Node_t *left;
    Node_t *right;
    Node_t *next;
};

#endif