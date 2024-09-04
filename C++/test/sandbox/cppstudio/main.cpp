#include <iostream>
#include <vector>


int main()
{
    long long x;
    std :: cin >> x;
    std :: vector<int> res;
    while(x > 0)
    {
        res.push_back(x % 10);
        x /= 10;
    }
    while(res.size())
    {
        std :: cout << res.back() << '\n';
        res.pop_back();
    }
    

    return 0;
}