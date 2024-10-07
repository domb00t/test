#include "bigint.h"

BigInt ::BigInt() : value_{}, sign_(false) {}

BigInt::BigInt(long long int value_) : value_{}, sign_(false)
{
    if (value_ < 0)
    {
        value_ *= -1;
        sign_ = true;
    }
    while (value_ != 0)
    {
        this->value_.insert(0, 1, static_cast<char>(value_ % 10));
        value_ /= 10;
    }
}

BigInt::BigInt(std::string number_) : value_{}, sign_(false)
{
    size_t index = 0;
    if (number_[0] == '-')
    {
        sign_ = true;
        ++index;
    }
    for (; index < number_.size(); ++index)
    {
        if (!isdigit(number_[index]))
        {
            throw "ERROR";
        }
        value_.push_back(static_cast<char>(static_cast<int>(number_[index]) - static_cast<int>('0')));
    }
}

BigInt::BigInt(const BigInt &other) : value_(other.value_), sign_(other.sign_) {}

BigInt &BigInt::operator=(const BigInt &other)
{
    BigInt copy = other;
    swap(copy);
    return *this;
}

BigInt &BigInt::operator+=(const BigInt &other)
{
    add(other);
    return *this;
}

void BigInt::add(const BigInt &other)
{
    BigInt copy = other;
    size_t diff = abs(value_.size() - copy.value_.size());
    if (value_.size() > copy.value_.size())
    {
        for (size_t index = 0; index < diff; ++index)
        {
            copy.value_.insert(0, 1, static_cast<char>(0));
        }
    }
    else
    {
        for (size_t index = 0; index < diff; ++index)
        {
            value_.insert(0, 1, static_cast<char>(0));
        }
    }

    int carry = 0;
    for (size_t index = 0; index < copy.value_.size(); ++index)
    {
        if (carry && (value_.size() - index - 1 == 0) && !sign_) // insert extra digit in front if number is positive
        {
            value_.insert(0, 1, static_cast<char>(carry));
        }
        int res = static_cast<int>(value_[value_.size() - index - 1]) + static_cast<int>(copy.value_[value_.size() - index - 1]) + carry;
        value_[value_.size() - index - 1] = static_cast<char>(res % 10);
        carry = (res / 10) % 10;

        // DEBUG
        //  std ::cout << index << " " << "res: " << res << std ::endl;
        //  std ::cout << *this << std ::endl;
        //  std ::cout << "carry: " << carry << std ::endl;
    }
}

void BigInt::sub(const BigInt &other)
{
    BigInt copy = other;
    if (other.sign_)
    {
    }
    else
    {
        for (size_t index = 0; index < value_.size(); ++index) {

        }
    }
}

bool operator<(const BigInt &left_, const BigInt &right_)
{
    if(left_.sign_ && right_.sign_) {
        
    }
    return less(left_,right_);
}

bool operator==(const BigInt &left_, const BigInt &right_)
{
   return equal(left_,right_);
}

bool operator!=(const BigInt &left_, const BigInt &right_)
{
    return !(left_ == right_);
}

BigInt abs(const BigInt &bigint_)
{
    return BigInt(bigint_.value_);
}

bool equal(const BigInt &left_, const BigInt &right_)
{
    return left_.sign_ == right_.sign_ && left_.value_ == right_.value_;
}

bool less(const BigInt &left_, const BigInt &right_)
{
    bool res = true;
    if(left_.sign_ && not right_.sign_) {
        return res;
    } else if(right_.sign_ && not left_.sign_) {
        return not res;
    } else if( left_.value_.size() < right_.value_.size()) {
        return res;
    } else if( left_.value_.size() > right_.value_.size()) {
        return not res;
    } else if( left_.value_ == right_.value_) {
        return not res;
    } 

    //TODO: compare two negative numbers

    int index = 0;
    while(index != left_.value_.size() && res) {
        if(static_cast<int>(left_.value_[index]) != static_cast<int>(right_.value_[index])) {
            if(!(static_cast<int>(left_.value_[index]) < static_cast<int>(right_.value_[index]))) res = false; 
        }
        ++index;
    }
    return res;
}

void BigInt::swap(BigInt &other)
{
    std ::swap(value_, other.value_);
    std ::swap(sign_, other.sign_);
}
std::ostream &operator<<(std::ostream &os, const BigInt &bigint_)
{

    if (bigint_.sign_)
    {
        os << '-';
    }
    for (size_t index = 0; index < bigint_.value_.size(); ++index)
    {
        os << static_cast<char>(static_cast<int>(bigint_.value_[index]) + static_cast<int>('0'));
    }
    os << std ::endl;
    return os;
}

std::istream &operator>>(std::istream &is, BigInt &&bigint_)
{
    //
}
