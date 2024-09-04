#include <iostream>

template <typename T> struct S {};

template <> struct S<double> {
  using type = double;
};

template <> struct S<float> {
  static constexpr int type = 32;
};

template <typename T> struct A {
  S<T>::type x;
};

int main() { return 0; }
