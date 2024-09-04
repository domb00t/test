#include <iostream>
#include "interface.h"
#include "bintree.h"
#include "linked_list.h"

void print(IData &);
void func(IData &);

int main()
{
    Bin_tree bintree;
    List list;
    int i, n;
    std ::cin >> n;
    for (i = 0; i < n; i++)
    {
        func(bintree);
        func(list);
    }

    std ::cout << "bntree\n";
    print(bintree);
    std ::cout << "list\n";
    print(list);

    return 0;
}

void func(IData &con)
{
    using std ::cin;
    using std ::cout;

    int value;

    cout << "Enter value:";
    cin >> value;

    con.addNode(value);
}

void print(IData &con)
{
    con.print();
}