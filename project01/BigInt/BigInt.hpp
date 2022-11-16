#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <cctype>

class BigInt
{
    friend inline std::ostream &operator<<(std::ostream &out, const BigInt &x);
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
            mIsNegative = true;
        }

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