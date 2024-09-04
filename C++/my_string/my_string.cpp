#include <iostream> 
#include <cstring>


class string {
public:
    string() : str(nullptr) , sz (0) , cap(0) {}
    string(size_t sz,char c) : string(sz) {
        memset(str,c,sz);
    }
    string(const string& other) : string(other.sz) {
        memcpy(this->str,other.str,other.cap);
    }
    string(const char* str) : string(strlen(str)) {
        memcpy(this->str,str,strlen(str) + 1);
    }

    string(std :: initializer_list<char> list) :string(list.size()) {
        std :: copy(list.begin(),list.end(),str);
    }

    string& operator=(const string& other) & {
        string copy = other; // making copy of other_str
        swap(copy); // swap with copy
        return *this;
    }

    size_t size() const {
        return sz;
    }

    size_t size() {
        return sz;
    }

    ~string() {
        delete[] str;
    }


private:

    friend std :: ostream& operator<<(std :: ostream& os,const string& str);

    friend bool operator==(const string& left,const string& right);
    friend bool operator!=(const string& left,const string& right);
    friend bool operator<(const string& left,const string& right);
    friend bool operator>(const string& left, const string& right);


    string(size_t sz) : str(new char[sz + 1]) , sz(sz) , cap(sz + 1) {
        str[sz] = '\0';
    }

    void swap(string& other) {
        std :: swap(str,other.str);
        std :: swap(sz,other.sz);
        std :: swap(cap,other.cap);
    }

    char* str;
    size_t sz;
    size_t cap;
};

std :: ostream& operator<<(std :: ostream& os,const string& str) {
    return os << str.str << std :: endl;
}

bool operator==(const string& left,const string& right) {
    if(left.size() != right.size()) {
        return false;
    }
    bool res = true;
    for(size_t i = 0;i < left.size() + 1;++i) { // O(n) strcmp imp
        res = res && !static_cast<bool>(left.str[i] ^ right.str[i]);
    }

    return res;
}

bool operator!=(const string& left,const string& right) {
    return !(left == right);
}

bool operator<(const string& left,const string& right) {
    return left.sz < right.sz;
}

bool operator>(const string& left, const string& right) {
    return left.sz > right.sz;
}



int main() {
    string s = "abc";
    string s2 = "abc";
    std :: cout << (s == s2);
    
    return 0;
}