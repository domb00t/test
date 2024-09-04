#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
using std ::size_t;

template <size_t M, size_t N, typename T>
class Matrix
{
public:
  Matrix();
  Matrix(const T &data);
  ~Matrix();
  void operator+=(const Matrix<M, N, T> &other);
  void operator-=(const Matrix<M, N, T> &other);
  void operator*=(const Matrix<M, N, T> &other);
  void operator/=(const Matrix<M, N, T> &other);

private:
  friend std ::ostream &operator<<(std ::ostream &os,
                                   const Matrix<M, N, T> &other);
  friend std ::istream &operator>>(std ::istream &is, Matrix<M, N, T> &other);
  T **ptr;
};

#endif
