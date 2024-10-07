#include <iostream>
#include <cmath>

int main()
{
    int Col = 3;
    int Row = 3;
    int **X;
    X = new int *[Row];
    for (size_t i = 0; i < Row; ++i)
    {
        X[i] = new int[Col];
    }

    for (size_t i = 0; i < Row; ++i)
    {
        for (size_t j = 0; j < Col; ++j)
        {
            X[i][j] = j + Col * i + 1;
        }
    }

    for (size_t i = 0; i < Row; ++i)
    {
        for (size_t j = 0; j < Col; ++j)
        {
            std ::cout << X[i][j] << '\t';
        }
    }

    for (size_t i = 0; i < Row; ++i)
    {
        delete[] X[i];
    }
    delete[] X;
}