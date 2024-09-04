#include <iostream>
#include <type_traits>
#include <algorithm>
#include <vector>

template<bool value>
struct S {
    static constexpr typename std :: conditional_t<value,int,double> x = 0;
};



int main() {
    std :: cout << typeid(S<false> :: x).name() << std :: endl;
    std :: vector<int> v = {1,5,8,12,99,23,22,110};
    std :: sort(v.begin(),v.end());
    std :: cout << std :: binary_search(v.begin(),v.end(),99);
}