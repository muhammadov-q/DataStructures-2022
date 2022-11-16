#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include <sstream>
#include <string>
#include <stdexcept>

#include "BigInt.hpp"

using namespace std;

TEST_CASE("default constructor")
{
    BigInt x;
    ostringstream sout;
    sout << x;
    REQUIRE(sout.str() == "0");

    vector<BigInt> v(5);
    for (auto &e : v)
    {
        ostringstream sout2;
        sout2 << e;
        REQUIRE(sout2.str() == "0");
    }
}

TEST_CASE("Constructor with a string")
{
    SUBCASE("Positive Number")
    {
        BigInt x("12345678912");
        ostringstream sout;
        sout << x;
        REQUIRE(sout.str() == "12345678912");
    }

    SUBCASE("Positive Number with +")
    {
        BigInt x("+12345678912");
        ostringstream sout;
        sout << x;
        REQUIRE(sout.str() == "12345678912");
    }

    SUBCASE("Negative Number")
    {
        BigInt x("-123");
        ostringstream sout;
        sout << x;
        REQUIRE(sout.str() == "-123");
    }

    SUBCASE("Empty string")
    {
        REQUIRE_THROWS_AS(BigInt(""), runtime_error);
    }

    SUBCASE("other cases to throw exception")
    {
        REQUIRE_THROWS_AS(BigInt("sdvs sdf asf"), runtime_error);
        REQUIRE_THROWS_AS(BigInt("12 12"), runtime_error);
        REQUIRE_THROWS_AS(BigInt("   -123"), runtime_error);
        REQUIRE_THROWS_AS(BigInt("-  123"), runtime_error);
    }
}
