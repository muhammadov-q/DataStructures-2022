#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

class BigInt
{
    friend inline std::ostream &operator<<(std::ostream &out, const BigInt &x);
    friend bool operator==(const BigInt &x, const BigInt &y);
    friend bool operator!=(const BigInt &x, const BigInt &y);
    friend inline BigInt operator+(const BigInt &x, const BigInt &y);
    std::vector<int> mDigits;
    bool mIsNegative;

public:
    BigInt()
        : mIsNegative(false)
    {
        mDigits.push_back(0);
    }

    BigInt(const std::string &s)
        : mIsNegative(false)
    {
        size_t i = 0;
        if( !s.empty() && (s[i] == '-' || s[i] == '+'))
        {
            mIsNegative = s[i] == '-';
            ++i;
        }
        while(i+1 < s.size() && s[i] == '0')
        {
            ++i;
        }
        for (;i < s.size() && isdigit(s[i]); i++)
        {
            mDigits.push_back(s[i] - '0');
        }
        if (i < s.size() || mDigits.empty())
        {
            throw std::runtime_error("BigInt: Incorrect string representation");
        }
        if (mDigits.size() == 1 && mDigits[0] == 0)
        {
            mIsNegative = false;
        }
    }

    static BigInt addAbsValues(const BigInt &x, const BigInt &y) 
    {
        auto itX = x.mDigits.rbegin();   
        auto itY = y.mDigits.rbegin();  

        BigInt z;
        z.mDigits.resize(std::max(x.mDigits.size(), y.mDigits.size()) + 1);
        auto itZ = z.mDigits.rbegin();

        int carry = 0;
        while (itX != x.mDigits.rend() || itY != y.mDigits.rend())
        {
            int s = carry;
            if(itX != x.mDigits.rend())
            {
                s += *itX;
                ++itX;
            }
            if(itY != y.mDigits.rend())
            {
                s += *itY;
                ++itY;
            }
            *itZ = s % 10;
            carry = (s > 9) ? 1 : 0;
            ++itZ;
        }
        if(carry != 0)
        {
            *itZ = carry;
        }
        if (z.mDigits.size() > 1 && z.mDigits.front() == 0)
        {
            z.mDigits.erase(z.mDigits.begin());
        }

        return z;
    }
};

inline std::ostream &operator<<(std::ostream &out, const BigInt &x)
{
    if (x.mIsNegative)
    {
        out << "-";
    }

    for (auto digit : x.mDigits)
    {
        out << digit;
    }

    return out;
}

inline bool operator==(const BigInt &x, const BigInt &y)
{
    return x.mIsNegative == y.mIsNegative && x.mDigits ==  y.mDigits;
}

inline bool operator!=(const BigInt &x, const BigInt &y)
{
    return !(x == y);
}

inline BigInt operator+(const BigInt &a, const BigInt &b)
{
    if (!a.mIsNegative && !b.mIsNegative)
    {
       return BigInt::addAbsValues(a, b);
    }
    if (a.mIsNegative && b.mIsNegative)
    {
        BigInt z = BigInt::addAbsValues(a, b);
        z.mIsNegative = true;
        return z; 
    }

    throw std::runtime_error("not implemented yet");
}