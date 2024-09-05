#include <iostream>

// TODO: UB - heap-buffer-overflow

template <typename T>
class vector
{
public:
    vector() : arr(nullptr), sz(0), cap(0) {}
    vector(size_t sz, T value = T()) : arr(new T[sz]), sz(sz), cap(sz * sizeof(T))
    {
        for (size_t index = 0; index < sz; ++index)
        {
            arr[index] = value;
        }
    }

    vector(const vector &other) : arr(new T[other.sz]), sz(other.sz), cap(other.cap)
    {
        for (size_t index = 0; index < other.sz; ++index)
        {
            this->arr[index] = other.arr[index];
        }
    }

    void push_back(T value)
    {
        T *_newarr = resrerve(sz + 1);
        for (size_t index = 0; index < sz + 1; ++index)
        {
            new (_newarr + index) T(arr[index]);
        }
        for (size_t index = 0; index < sz; ++index)
        {
            (arr + index)->~T();
        }
        new (_newarr + sz) T(value);
        delete[] reinterpret_cast<char *>(arr);
        arr = _newarr;
        sz += 1;
        cap += sizeof(T);
    }

    vector &operator=(const vector &other)
    {
        vector copy = other;
        swap(copy);
        return *this;
    }

    ~vector()
    {
        delete[] reinterpret_cast<char *>(arr);
    }

private:
    // memory reserve
    T *resrerve(size_t sz)
    {
        T *_newarr = nullptr;
        try
        {
            _newarr = reinterpret_cast<T *>(new char[sz * sizeof(T)]);
        }
        catch (std ::bad_alloc &exc)
        {
            std ::cout << exc.what() << std ::endl;
            std ::abort();
        }
        return _newarr;
    }
    friend std ::ostream &operator<<(std ::ostream &os, const vector<T> &vec)
    {
        for (size_t index = 0; index < vec.sz; ++index)
        {
            os << vec.arr[index] << ' ';
        }
        os << std ::endl;
        return os;
    }

    void swap(vector &other)
    {
        std ::swap(arr, other.arr);
        std ::swap(sz, other.sz);
        std ::swap(cap, other.cap);
    }

    T *arr;
    size_t sz;
    size_t cap;
};

int main()
{
    vector<int> v(5, 4);
    std ::cout << v;
    v.push_back(3);
    std ::cout << v;
    return 0;
}
