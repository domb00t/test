#include <iostream>

int main()
{
    double* pd;
    size_t n;
    std ::cin >> n;
    pd = (double *)malloc(n * sizeof(double));
    if (pd != NULL)
    {
        for (size_t i = 0; i < n; i++)
        {
            pd[i] = (i + 1);
        }
        for (size_t i = 0; i < n; i++)
        {
            std ::cout << pd[i] << "\t";
        }
    }
    else
    {
        std :: cerr << "malloc error";
    }
    free(pd);
    return 0;
}