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

TEST_CASE("constructor with long long paramater")
{
    ostringstream sout;
    for (int i = -1000; i < 1000; i++)
    {
        BigInt x(i);
        sout << x;
        REQUIRE(sout.str() == to_string(i));
        sout.str("");
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

    SUBCASE("Test with -0 == +0")
    {
        BigInt x("+000");
        BigInt y("-0");

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

TEST_CASE("bigInt: operator < and >")
{
    SUBCASE("negative and positive, operator<")
    {
        REQUIRE(BigInt("-123") < BigInt("1"));
        REQUIRE(BigInt("-123") < BigInt("0"));
        REQUIRE(BigInt("-123") < BigInt("123"));
        REQUIRE_FALSE(BigInt("1") < BigInt("-123"));
        REQUIRE_FALSE(BigInt("0") < BigInt("-123"));
        REQUIRE_FALSE(BigInt("123") < BigInt("-123"));
    }

    SUBCASE("positives, operator<")
    {
        REQUIRE(BigInt("909") < BigInt("981"));
        REQUIRE(BigInt("99") < BigInt("9999"));
        REQUIRE(BigInt("0") < BigInt("1"));
    }

    SUBCASE("negatives, operator<")
    {
        REQUIRE(BigInt("-12") < BigInt("-1"));
        REQUIRE(BigInt("-123") < BigInt("-12"));
        REQUIRE(BigInt("-111") < BigInt("-2"));
        REQUIRE(BigInt("-222") < BigInt("-111"));
    }

    SUBCASE("negative and positive, operator>")
    {
        REQUIRE(BigInt("1") > BigInt("-123"));
        REQUIRE(BigInt("0") > BigInt("-123"));
        REQUIRE(BigInt("123") > BigInt("-123"));
        REQUIRE_FALSE(BigInt("-123") > BigInt("1"));
        REQUIRE_FALSE(BigInt("-123") > BigInt("0"));
        REQUIRE_FALSE(BigInt("-123") > BigInt("123"));
    }

    SUBCASE("positive, operator>")
    {
        REQUIRE(BigInt("989") > BigInt("981"));
        REQUIRE(BigInt("9999") > BigInt("99"));
        REQUIRE(BigInt("1") > BigInt("0"));
    }

    SUBCASE("negatives, operator>")
    {
        REQUIRE(BigInt("-1") > BigInt("-12"));
        REQUIRE(BigInt("-12") > BigInt("-123"));
        REQUIRE(BigInt("-2") > BigInt("-111"));
        REQUIRE(BigInt("-111") > BigInt("-222"));
    }
}

TEST_CASE("bigInt: operator <= and >=")
{
    
    SUBCASE("negative and positive, operator<=")
    {
        REQUIRE(BigInt("1") <= BigInt("1"));
        REQUIRE(BigInt("-123") <= BigInt("0"));
        REQUIRE(BigInt("123") <= BigInt("123"));
        REQUIRE_FALSE(BigInt("1") <= BigInt("-123"));
        REQUIRE_FALSE(BigInt("0") <= BigInt("-123"));
        REQUIRE_FALSE(BigInt("123") <= BigInt("-123"));
    }

    SUBCASE("positives, operator<=")
    {
        REQUIRE(BigInt("981") <= BigInt("981"));
        REQUIRE(BigInt("99") <= BigInt("9999"));
        REQUIRE(BigInt("0") <= BigInt("1"));
    }

    SUBCASE("negatives, operator<=")
    {
        REQUIRE(BigInt("-12") <= BigInt("-1"));
        REQUIRE(BigInt("-123") <= BigInt("-12"));
        REQUIRE(BigInt("-111") <= BigInt("-2"));
        REQUIRE(BigInt("-134") <= BigInt("-123"));
        REQUIRE(BigInt("-222") <= BigInt("-222"));
    }

    SUBCASE("negative and positive, operator>=")
    {
        REQUIRE(BigInt("1") >= BigInt("-123"));
        REQUIRE(BigInt("0") >= BigInt("0"));
        REQUIRE(BigInt("123") >= BigInt("-123"));
        REQUIRE_FALSE(BigInt("-123") >= BigInt("1"));
        REQUIRE_FALSE(BigInt("0") >= BigInt("1"));
        REQUIRE_FALSE(BigInt("-123") >= BigInt("123"));
    }

    SUBCASE("positive, operator>=")
    {
        REQUIRE(BigInt("989") >= BigInt("981"));
        REQUIRE(BigInt("9999") >= BigInt("99"));
        REQUIRE(BigInt("1") >= BigInt("1"));
    }

    SUBCASE("negatives, operator>")
    {
        REQUIRE(BigInt("-1") >= BigInt("-12"));
        REQUIRE(BigInt("-12") >= BigInt("-123"));
        REQUIRE(BigInt("-2") >= BigInt("-111"));
        REQUIRE(BigInt("-1") >= BigInt("-1"));
        REQUIRE(BigInt("-111") >= BigInt("-222"));
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
    
    SUBCASE("Positive + negative")
    {
        BigInt x("193");
        BigInt y("-10");
        sout << x + y;
        REQUIRE(sout.str() == "183");

        BigInt x1(100);
        BigInt y1(-200);
        REQUIRE(x1 + y1 == 100 - 200);
    }

    SUBCASE("negative + Positive")
    {
        BigInt x("-10");
        BigInt y("193");
        sout << x + y;
        REQUIRE(sout.str() == "183");

        BigInt x1(-100);
        BigInt y1(99);
        REQUIRE(x1 + y1 == 99 - 100);
    }
}

TEST_CASE("Substruction")
{
    ostringstream sout;
    SUBCASE("Positive - positive")
    {
        BigInt x(100);
        BigInt y(50);
        REQUIRE(x - y == 100 - 50);

        BigInt x1(2024);
        BigInt y1(576);
        REQUIRE(x1 - y1 == 2024 - 576);
        
        BigInt x2(1000);
        BigInt y2(1);
        REQUIRE(x2 - y2 == 1000 - 1);

        BigInt x3(1);
        BigInt y3(100);
        REQUIRE(x3 - y3 == 1 - 100);
    }
    
    SUBCASE("Positive - negative")
    {
        BigInt x("100");
        BigInt y("-50");
        sout << x - y;
        REQUIRE(sout.str() == "150");
    }

    SUBCASE("negative - negative")
    {
        BigInt x("-10");
        BigInt y("-12");
        sout << x - y;
        REQUIRE(sout.str() == "2");

        BigInt x1(-20);
        BigInt y1(-10);
        REQUIRE(x1 - y1 == 10 - 20);
    }
}

TEST_CASE(" -= and +=")
{
    BigInt x(100);
    BigInt y(10);
    x -= y;
    REQUIRE(x == 90);
    
    BigInt x1(20);
    BigInt y1(10);
    x1 += y1;
    REQUIRE(x1 == 30);
}


TEST_CASE(" -- and ++")
{
    SUBCASE("--")
    {
        BigInt x(100);
        x--;
        REQUIRE(x == 99);
    
        BigInt x3(1);
        --x3;
        REQUIRE(x3 == 0);
    }

    SUBCASE("++")
    {
        BigInt x1(20);
        x1++;
        REQUIRE(x1 == 21);

        BigInt x2(0);
        ++x2;
        REQUIRE(x2 == 1);
    }
}

TEST_CASE("Input operator")
{
    ostringstream sout;
    SUBCASE("correct input #1")
    {
        istringstream sinp("123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.eof());
        REQUIRE(x == 123);
    }

    SUBCASE("correct input #2")
    {
        istringstream sinp("  123 ");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.good());
        REQUIRE(x == 123);
    }

    SUBCASE("correct input #3")
    {
        istringstream sinp("123u123");
        BigInt x;
        char ch;
        sinp >> x >> ch;
        REQUIRE(sinp.good());
        REQUIRE(x == 123);
        REQUIRE(ch == 'u');
    }

    SUBCASE("correct input #4")
    {
        istringstream sinp("  -123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.eof());
        REQUIRE(x == -123);
    }

    SUBCASE("correct input #5")
    {
        istringstream sinp("  +000000123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.eof());
        REQUIRE(x == 123);
    }

    SUBCASE("correct input #6")
    {
        istringstream sinp("-0000000");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.eof());
        REQUIRE(x == 0);
    }

    SUBCASE("Incorrect input #1")
    {
        istringstream sinp("+  123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.fail());
        REQUIRE(x == 0);
    }

    SUBCASE("Incorrect input #2")
    {
        istringstream sinp("++123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.fail());
        REQUIRE(x == 0);
    }

    SUBCASE("Incorrect input #3")
    {
        istringstream sinp("hello");
        BigInt x;
        char ch;
        sinp >> x;
        REQUIRE(sinp.fail());
        sinp.clear();
        sinp >> ch;
        REQUIRE(x == 0);
        REQUIRE(ch == 'h');
    }

    SUBCASE("Incorrect input #4")
    {
        istringstream sinp("");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.fail());
        REQUIRE(sinp.eof());
        REQUIRE(x == 0);
    }
}

TEST_CASE("abs() function")
{
    BigInt x(-20);
    REQUIRE(abs(x) == 20);

    BigInt y(20);
    REQUIRE(abs(y) == 20);
}
