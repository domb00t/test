#include <iostream>

int main()
{
    const int size = 100;
    int X[size];
    int x;
    std ::cin >> x;
    int i = 0;
    int top = 0;
    while (x != 0)
    {
        X[i++] = x;
        std ::cin >> x;
        top += 1;
    }
    std :: cout <<  top << std :: endl;
    i = 0;
    while (X[i] != 0)
    {
        std ::cout << X[i++] << '\t';
    }
    i = 0;
    std ::cout << '\n';
    int temp = top;
    while (top != 0)
    {
        std ::cout << X[--top] << "\t";
    }
    std :: cout << '\n' << "sorting\n";
    bool fl = false;
    while (!fl)
    {
        fl = true;
        i = 0;
        while (i < temp - 1)
        {
            if (X[i] > X[i + 1])
            {
                int tmp = X[i];
                X[i] = X[i+1];
                X[i+1] = tmp;
                fl = false;
            }
            for(int j = 0;j<temp;j++){std :: cout <<X[j] << '\t';}
            std :: cout << '\n';
            i++;
        }
    }
    std :: cout << '\n';
    i = 0;
    while (X[i] != 0)
    {
        std ::cout << X[i++] << '\t';
    }
}