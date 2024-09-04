#include <iostream>
// #include <execution>

double division(double x,double y) try {
  if(y == 0.0) {
    throw std::invalid_argument("dividing by zero");
  }
  return x / y;
}catch(std :: invalid_argument& ex) {
  std :: cerr << ex.what() << std :: endl;
  return 0;
}

typedef struct S {
  int a;
  S() : a(3) { std :: cout << "S " << this << std :: endl;}
  S(const S& other) : a(other.a) { std :: cout << "copy to  " << this <<std :: endl;}
  ~S() {std :: cout << "~S " << this <<  std :: endl;}
} exception_t;

void f(int a) {
  if(a == 0) {
    exception_t exp;
    throw exp;
  }
  std :: cout << "all good" << std :: endl;
}

int main() {
  int x;
  std :: cin >> x;
  try {
    f(x);
  }catch(exception_t& ex) {
    std :: cout << "ex_value " <<  ex.a << ' ' << &ex <<std :: endl;
  }
  std :: cout << "main ended" << std :: endl;
  return 0;
}