#include <iostream>
#include "func.h"

void f() {
    for(int i =0;i < 10;++i) {
        std :: cout << i + 1 << '\t';
    }
}

template<typename T>
struct S {
    T x;
};

int main() {
    f();
    std :: cout << "\n";
    std :: cout << addition(3,4);
    std :: cout << " ";
    return 0;
}