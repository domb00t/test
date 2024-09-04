#include <iostream>

class Array
{
public:
    Array() : sz(0), arr(nullptr) {}
    Array(size_t size) : sz(size), arr(nullptr)
    {
        reserve(sz);
    }
    Array(size_t size, int value) : Array(size)
    {
        for (size_t index = 0; index < sz; ++index)
        {
            arr[index] = value;
        }
    }
    Array(const Array &other);
    ~Array()
    {
        _free();
    }

private:
    friend std ::ostream &operator<<(std ::ostream &os, const Array &arr);

    void reserve(size_t size)
    {
        try{
        arr = reinterpret_cast<int *>(new char[sizeof(int) * 100000000000000000]);
        }catch(std :: bad_alloc& exc) {
            std :: cerr << exc.what() << std :: endl;
            std :: cerr << "reserve function fault" << std :: endl;
        }
        for (size_t index = 0; index < size; ++index)
        {
            arr[index] = int();
        }
    }
    void _free()
    {
        delete[] reinterpret_cast<char *>(arr);
    }
    size_t sz;
    int *arr;
};

int main()
{
    Array arr(3, 6);
    std :: cout << arr;
    return 0;
}

std ::ostream &operator<<(std ::ostream &os, const Array &arr)
{
    for (size_t index = 0; index < arr.sz; ++index)
    {
        os << arr.arr[index] << ' ';
    }
    os << std :: endl;
    return os;
}
