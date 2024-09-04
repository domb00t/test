#include <iostream> 

template<typename T>
T* reserve(size_t sz) {
  T* res = reinterpret_cast<T*>(new char(sizeof(T) * sz));
  for(size_t index = 0;index < sz;++index) {
    new(res + index)T();
  }
  return res;
}

template<typename T>
void my_delete(T* arr,size_t sz) {
  for(size_t index = 0;index < sz;++ index) {
    (arr+index)->~T();
  }
  delete[] reinterpret_cast<char*>(arr);
}

int main() {
  int* ptr = reserve<int>(3);
  for(size_t index = 0;index < 3;++index){
    std :: cout << ptr[index] << '\t';
  }
  my_delete<int>(ptr,3);
  return 0;
}