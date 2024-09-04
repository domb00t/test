#include <iostream>

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
    return 0;
}