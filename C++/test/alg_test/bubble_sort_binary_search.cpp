#include <iostream> 


void bubble_sort(int* X) {

    bool fl = false;
    while (!fl)
    {
        fl = true;
        int i = 0;
        while (i < (sizeof(X) / sizeof(int)) - 1)
        {
            if (X[i] > X[i + 1])
            {
                int tmp = X[i];
                X[i] = X[i+1];
                X[i+1] = tmp;
                fl = false;
            }
            i++;
        }
    }
    for(int i = 0;i < (sizeof(X) / sizeof(int)); ++i) {
        std :: cout << X[i] << "\t";
    }
}
bool bin_search(int* arr,int sz,int x) {
    bubble_sort(arr);
    int l = 0;
    int r = sz - 1;
   while(l <= r) {
        int q = (r + l) / 2;
        if(arr[q] == x) return true;
        else if ( arr[q] < x) {
            l = q + 1;
        } else {
            r = q - 1;
        }
    }
    return false;
}

int main() { 
    int X[] = {1,3,2,15,4,5,6,7,8,9,10};
    for(int x : X) {
        std :: cout << x << "\t";
    }
    int x = 0;
    std :: cin >> x;
    std :: cout << (bin_search(X,(sizeof(X) / sizeof(int)),x) ?  "yes" : "no" );
    return 0;
}