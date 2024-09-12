#include <iostream>
#include "bigint.h"

int main() { 
    /*
    std :: string str = "-2";
    BigInt x(str) ;
    BigInt y(2489421548465948);
    BigInt z(y);
    BigInt f = z;
    std :: cout << x;
    std :: cout << y;
    std :: cout << z;
    std :: cout << f;
    */

   BigInt x("1");
   BigInt y("56");
   BigInt z = (x+=y);
   std :: cout << z;

    return 0;
};