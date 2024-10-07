#include <iostream>
#include "bigint.h"

int main()
{
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

    /*
        BigInt x("9929");
        BigInt y("9939");
        BigInt e(-321);
        BigInt z = (x += y);
        std ::cout << z << std ::endl;
        std ::cout << (x < y) << std ::endl;
    */
   int z = 0;
   bool h = z;
    BigInt x("999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
    BigInt y("-19");
    //std ::cout << (x == y) << std ::endl;
    std ::cout << (x < y) << std ::endl;

    //std :: cout << x.getSign() << std :: endl;

    return 0;
};