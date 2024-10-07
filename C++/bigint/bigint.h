#ifndef __BIGINT_H__
#define __BIGINT_H__

#include <iostream>
#include <string>
#include <cmath>

class BigInt
{
public:
    BigInt();
    explicit BigInt(long long int value_);
    BigInt(std ::string number);
    BigInt(const BigInt &other);
    BigInt &operator=(const BigInt &other);

    BigInt &operator+=(const BigInt &other);
    BigInt &operator-=(const BigInt &other);
    BigInt &operator*=(const BigInt &other);
    BigInt &operator/=(const BigInt &other);

    BigInt operator-();

    // probably
    operator int();
    operator unsigned long long();
    operator long long();

    bool getSign() const
    {
        return sign_;
    }

    ~BigInt() = default;

private:
    friend std ::ostream &operator<<(std ::ostream &os, const BigInt &bigint_);
    friend std ::istream &operator>>(std ::istream &is, BigInt &&bigint_);

    friend bool operator<(const BigInt &left_, const BigInt &right_);
    friend bool operator==(const BigInt &left_, const BigInt &right_);
    friend bool operator!=(const BigInt &left_, const BigInt &right_);
    friend BigInt abs(const BigInt& bigint_);


    /*
    friend bool operator>(const BigInt &right_, const BigInt &left_);
    
    */

    void add(const BigInt &other);
    void sub(const BigInt &other);
    friend bool equal(const BigInt &left_, const BigInt &right_);
    friend bool less(const BigInt &left_, const BigInt &right_);

    void swap(BigInt &other);

    std ::string value_;
    bool sign_;
};

#endif