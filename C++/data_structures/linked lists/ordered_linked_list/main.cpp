#include <iostream>
#include "linked_list.h"

int main ()
{
    List l1;
    int n;
    std :: cin >> n;
    for(int i = 0;i < n;i++)
    {
        l1.addNode(-1*(n-i));
    }
    l1.print();

    return 0;
}