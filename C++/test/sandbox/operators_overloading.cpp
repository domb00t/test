#include <iostream>

class MyClass
{
private:
    int size;
    int *parr;

public:
    MyClass() : size{0}, parr{nullptr} { std ::cout << "contsract\n"; }
    MyClass(int size)
    {
        this->size = size;
        parr = new int[size];
        for (int i = 0; i < size; i++)
        {
            parr[i] = i;
        }
        std ::cout << "contsract\n";
    }
    MyClass(const MyClass &other)
    {
        this->size = other.size;
        this->parr = new int[other.size];
        for (int i = 0; i < other.size; i++)
        {
            this->parr[i] = other.parr[i];
        }
        std ::cout << "copy\n";
    }
    ~MyClass()
    {
        if (parr != nullptr)
        {
            delete[] this->parr;
        }
        std ::cout << "destructor\n";
    }
    void print()
    {
        if (parr != nullptr && size != 0)
        {
            for (int i = 0; i < size; i++)
            {
                std ::cout << parr[i] << "\t";
            }
            std ::cout << "\n";
        }
        else
        {
            std ::cout << "is empty\n";
        }
    }
    MyClass& operator=(const MyClass &other)
    {
        if (this->parr != nullptr)
        {
            delete[] this->parr;
        }
        this->size = other.size;
        this->parr = new int[other.size];
        for (int i = 0; i < size; i++)
        {
            this->parr[i] = other.parr[i];
        }
        return *this;
    }
    int& operator[](int index)
    {
        return this->parr[index];
    }
    bool operator==(const MyClass &other)
    {
        if (this->size != other.size)
        {
            return false;
        }
        bool fl = true;
        for (int i = 0; i < other.size; i++)
        {
           if(this->parr[i] != other.parr[i]) fl = false;
        }
        return fl;
    }
};

int main()
{
    MyClass a(5);
    MyClass b(5);
    a[0] = 9;
    a.print();
    b.print();
    std ::cout << (a == b) << std ::endl;
    a[0] = 0;
    std ::cout << (a == b) << std ::endl;

    return 0;
}