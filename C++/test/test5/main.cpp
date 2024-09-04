#include <iostream> 

int lin_search(int* arr,int size,int value) { 
    int tmp = arr[size - 1];
    arr[size - 1] = value;
    int index = 0;
    while(arr[index] != value) ++index;
    arr[size - 1] = tmp;
    if(index < size - 1 || arr[size - 1] == value) return index;
    else std :: abort();
    return -1;
}

int main() {
    int X[] = {1,2,3,4,5,6,7,8};
    std :: cout << lin_search(X,8,0);
    return 0;
}