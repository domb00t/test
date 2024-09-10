#ifndef __BIGINT_H__
#define __BIGINT_H__

#include <string>

class BigInt
{
public:
    BigInt();
    explicit BigInt(int value);
    BigInt(std ::string number);
    BigInt(const BigInt &other);
    BigInt &operator=(const BigInt &other);

    BigInt &operator+=(const BigInt &other);
    BigInt &operator-=(const BigInt &other);
    BigInt &operator*=(const BigInt &other);
    BigInt &operator/=(const BigInt &other);

    operator int();

    ~BigInt() = default;

private:
    friend std ::ostream &operator<<(std ::ostream &os, const BigInt &bigint_);
    friend std ::istream &operator>>(std ::istream &is, BigInt &&bigint_);

    friend BigInt operator+(const BigInt &right_, const BigInt &left_);
    friend BigInt operator-(const BigInt &right_, const BigInt &left_);
    friend BigInt operator*(const BigInt &right_, const BigInt &left_);
    friend BigInt operator/(const BigInt &right_, const BigInt &left_);

    void swap(BigInt &other);

    std ::string number_;
    bool sign_;
};

#endif