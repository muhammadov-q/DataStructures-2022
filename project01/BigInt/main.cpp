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

TEST_CASE("Constructor with a string parametr")
{
    ostringstream sout;
    SUBCASE("jsut a very long positive number positive Number")
    {
        BigInt x("12345678912");
        sout << x;
        REQUIRE(sout.str() == "12345678912");
    }

    SUBCASE("Positive Number with +")
    {
        BigInt x("+123");
        sout << x;
        REQUIRE(sout.str() == "123");
    }

    SUBCASE("Negative Number with sign -")
    {
        BigInt x("-123");
        sout << x;
        REQUIRE(sout.str() == "-123");
    }

    SUBCASE("Empty string")
    {
        REQUIRE_THROWS_AS(BigInt(""), runtime_error);
    }

    SUBCASE("leading zeros")
    {
        BigInt x("0000000123");
        sout << x;
        REQUIRE(sout.str() == "123");

        sout.str("");
        BigInt k("+0000000");
        sout << k;
        REQUIRE(sout.str() == "0");

        sout.str("");
        BigInt y("-0000000123");
        sout << y;
        REQUIRE(sout.str() == "-123");

        sout.str("");
        BigInt z("-0");
        sout << z;
        REQUIRE(sout.str() == "0");
    }

    SUBCASE("just sign")
    {
        REQUIRE_THROWS_AS(BigInt("-"), runtime_error);
        REQUIRE_THROWS_AS(BigInt("+"), runtime_error);
    }

    SUBCASE("other cases to throw exception")
    {
        REQUIRE_THROWS_AS(BigInt("sdvs sdf asf"), runtime_error);
        REQUIRE_THROWS_AS(BigInt("hello"), runtime_error);
        REQUIRE_THROWS_AS(BigInt("12 12"), runtime_error);
        REQUIRE_THROWS_AS(BigInt("   -123"), runtime_error);
        REQUIRE_THROWS_AS(BigInt("-  123"), runtime_error);
        REQUIRE_THROWS_AS(BigInt("123-123"), runtime_error);
        REQUIRE_THROWS_AS(BigInt(" 123 "), runtime_error);
    }
}

TEST_CASE("bigInt: operator ==")
{
    ostringstream sout;
    SUBCASE("Test with -1234 == -65")
    {
        BigInt x("-1234");
        BigInt y("-65");

        REQUIRE(!(x == y));
    }

    SUBCASE("Test with 1 == -65")
    {
        BigInt x("1");
        BigInt y("1");

        REQUIRE(x == y);
    }

    SUBCASE("Test with -1 == -0001")
    {
        BigInt x("-1");
        BigInt y("-00001");

        REQUIRE(x == y);
    }

    SUBCASE("Test with 10 == 10")
    {
        BigInt x("+10");
        BigInt y("+000010");

        REQUIRE(x == y);
    }
}

TEST_CASE("bigInt: operator !=")
{
    ostringstream sout;
    SUBCASE("Test with -1234 != -65")
    {
        BigInt x("-1234");
        BigInt y("-65");

        REQUIRE(x != y);
    }

    SUBCASE("Test with 1 != -65")
    {
        BigInt x("1");
        BigInt y("-65");

        REQUIRE(x != y);
    }

    SUBCASE("Test with 10 != 10")
    {
        BigInt x("10");
        BigInt y("10");

        REQUIRE(!(x != y));
    }
}

TEST_CASE("Addition")
{
    ostringstream sout;
    SUBCASE("Positive + positive")
    {
        BigInt x("193");
        BigInt y("59");
        sout << x + y;
        REQUIRE(sout.str() == "252");
    }

    SUBCASE("negative + negative")
    {
        BigInt x("-193");
        BigInt y("-59");
        sout << x + y;
        REQUIRE(sout.str() == "-252");
    }
    
    // SUBCASE("Positive + negative")
    // {
        
    // }
    // SUBCASE("negative + Positive")
    // {
        
    // }
    
}
