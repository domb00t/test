#include "matrix.h"

template <size_t M, size_t N, typename T>
Matrix<M, N, T>::Matrix() : ptr(nullptr) {}

template <size_t M, size_t N, typename T>
Matrix<M, N, T>::Matrix(const T &data) : ptr(new T *[M]) {
  for (size_t i = 0; i < M; ++i) {
    ptr[i] = new T[N];
  }
  for (size_t i = 0; i < M; ++i) {
    for (size_t j = 0; j < N; ++j) {
      ptr[i][j] = data();
    }
  }
}

template <size_t M, size_t N, typename T>
std ::ostream &operator<<(std ::ostream &os, const Matrix<M, N, T> &other) {
  for (size_t i = 0; i < M; ++i) {
    for (size_t j = 0; j < N; ++j) {
      os << other.ptr[i][j];
    }
    os << '\n';
  }
  return os;
}

template <size_t M, size_t N, typename T>
std ::istream &operator>>(std ::istream &is, Matrix<M, N, T> &other) {
  for (size_t i = 0; i < M; ++i) {
    for (size_t j = 0; j < N; ++j) {
      is >> other.ptr[i][j];
    }
  }
  return is;
}

template <size_t M, size_t N, typename T> Matrix<M, N, T>::~Matrix() {
  for (size_t i = 0; i < M; ++i) {
    delete[] ptr[i];
  }
  delete[] ptr;
}

template <size_t M, size_t N, typename T>
void Matrix<M, N, T>::operator+=(const Matrix<M, N, T> &other)
{
}

template <size_t M, size_t N, typename T>
void Matrix<M, N, T>::operator*=(const Matrix<M, N, T> &other)
{
}
