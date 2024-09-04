#include <iostream>
#include "class.h"
#include "func.h"

int main ()
{
    DL_List list_;
    int x;
    std :: cin >> x;

    for(int i=0;i<x;i++)
    {
        list_.addNode(fact(i+1));
    }
    list_.printList();
    std :: cout << "\n";
    list_.revPrint();
}