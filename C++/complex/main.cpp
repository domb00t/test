#include <iostream>
#include <ostream>

template <typename T> void swap(T &left, T &right) {
  T tmp = left;
  left = right;
  right = tmp;
}

class Complex {
private:
  double real = 0.0;
  double image = 0.0;

  friend std ::ostream &operator<<(std ::ostream &os, const Complex &other);
  friend std ::istream &operator>>(std ::istream &is, Complex &other);

public:
  Complex() : real(0.0), image(0.0) {}
  explicit Complex(double real) : real(real) {}
  Complex(double real, double image) : real(real), image(image) {}
  Complex(const Complex &other) : Complex(other.real, other.image) {}
  Complex operator-() const;

  Complex &operator=(const Complex &other);
  Complex &operator+=(const Complex &other);
  Complex &operator-=(const Complex &other);
  Complex &operator*=(const Complex &other);
  Complex &operator/=(const Complex &other);

  Complex operator+(const Complex &other);
  Complex operator-(const Complex &other);
  Complex operator*(const Complex &other);
  Complex operator/(const Complex &other);

  ~Complex() = default;
};

int main() {
  Complex z1, z2;
  std ::cin >> z1;
  std ::cin >> z2;
  std ::cout << z1;
  Complex z3 = z1 + z2;
  std ::cout << z3;

  return 0;
}

Complex &Complex ::operator=(const Complex &other) {
  if (this == &other) {
    return *this;
  }
  this->real = other.real;
  this->image = other.image;
  return *this;
}

Complex Complex ::operator-() const { return Complex(-real, -image); }

Complex &Complex ::operator+=(const Complex &other) {
  this->real += real;
  this->image += image;
  return *this;
}

Complex &Complex ::operator-=(const Complex &other) { return *this += -other; }

Complex Complex ::operator+(const Complex &other) {
  return Complex(*this) += other;
}

Complex Complex ::operator-(const Complex &other) {
  return Complex(*this) -= other;
}

Complex &Complex ::operator*=(const Complex &other) {
  this->real = this->real * other.real - this->image * other.image;
  this->image = this->image * other.real + this->real * other.image;
  return *this;
}

Complex &Complex ::operator/=(const Complex &other) {
  this->real = (this->real * other.real + this->image * other.image) /
               (other.real * other.real + other.image * other.image);
  this->image = (other.real * this->image - this->real * other.image) /
                (other.real * other.real + other.image * other.image);
  return *this;
}

Complex Complex ::operator*(const Complex &other) {
  return Complex((*this) *= other);
}

Complex Complex ::operator/(const Complex &other) {
  return Complex((*this) /= other);
}

std ::ostream &operator<<(std ::ostream &os, const Complex &other) {
  return os << "(" << other.real << "," << other.image << ")\n";
}

std ::istream &operator>>(std ::istream &is, Complex &other) {
  return is >> other.real >> other.image;
}
