#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std :: istream_iterator<int> iter(std :: cin);
    std :: vector<int> v;
    for(size_t index = 0;index < 5;++index,++iter) {
        v.push_back(*iter);
    }
    for(const auto& x : v) {
        std :: cout << x << " ";
    }
    return 0;
}