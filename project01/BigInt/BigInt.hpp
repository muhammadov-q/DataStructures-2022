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
        if (s == "")
        {
            throw std::runtime_error("BigInt can not be empty");
        }

        for (auto e : s)
        {
            if (e == '+' || e == '-')
            {
                continue;
            }
            else if (!isdigit(e))
            {
                throw std::runtime_error("BigInt entered wrongly");
            }
        }

        for (auto d : s)
        {
            if (d == '+')
            {
                continue;
            }
            else
            {
                mDigits.push_back(d - '0');
            }
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