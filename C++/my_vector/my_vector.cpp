#include <iostream>

template<typename T>
class vector {
public:
    vector() : arr(nullptr) , sz(0) , cap(0) {}
    vector(const vector& other) : arr(new T[other.sz]) , sz(other.sz) , cap(other.cap) {
        for(size_t index = 0;index < other.sz;++index) {
            this->arr[index] = other.arr[index];
        }
    }
    vector& operator=(const vector& other);
    ~vector();
private:
    
    //memory reserve
    void reserve(size_t sz) {
        try{
            arr = reinterpret_cast<T*>(new char[sizeof(T)  * sz]); // allocates sizeof(T) * N bytes 
        } catch(std :: bad_alloc& ex) {
            std :: cout << ex.what() << std :: endl;
        }
        for(size_t index = 0;index < sz;++index) {
            new(arr + index)T(); // default inicialization
        }
    }

    T* arr;
    size_t sz;
    size_t cap;
};

int main() {
    return 0;
}