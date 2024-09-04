#include <iostream>

struct A {
    void operator()() const { std :: cout << "Hello world!\n"; }
};

int main() {
    A f;
    f();
    return 0;
}
