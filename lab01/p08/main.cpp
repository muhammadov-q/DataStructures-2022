#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include <sstream>
#include <vector>

#include "Rational.hpp"

using namespace std;

TEST_CASE("Default constructor")
{
    const Rational<int> x;

    REQUIRE(x.num() == 0);
    REQUIRE(x.den() == 1);

    vector<Rational<long long>> v(10);

    for (auto r : v)
    {
        REQUIRE(r.num() == 0);
        REQUIRE(r.den() == 1);
    }

    ostringstream sout;
    sout << x;

    REQUIRE(sout.str() == "0/1");
}

TEST_CASE("Constructor Rational(num, den)")
{
    std::ostringstream sout;

    SUBCASE("denominator is equal to zero")
    {
        REQUIRE_THROWS_AS(Rational<int>(5, 0), std::runtime_error);
    }

    SUBCASE("reducing 20/10")
    {
        Rational<int> x(20, 10);
        sout << x;

        REQUIRE(sout.str() == "2/1");
    }

    SUBCASE("reducing 10/25")
    {
        Rational<int> x(10, 25);
        sout << x;

        REQUIRE(sout.str() == "2/5");
    }
    SUBCASE("reducing 11/17")
    {
        Rational<int> x(11, 17);
        sout << x;

        REQUIRE(sout.str() == "11/17");
    }
    SUBCASE("reducing 28/-12")
    {
        Rational<int> x(28, -12);
        sout << x;
        REQUIRE(sout.str() == "-7/3");
    }

    SUBCASE("reducing 6/1")
    {
        Rational<int> x(6);
        sout << x;
        REQUIRE(sout.str() == "6/1");
    }
}

TEST_CASE("Addition")
{
    ostringstream sout;
    SUBCASE("1/2 + 2/3")
    {
        Rational<int> x(1, 2);
        Rational<int> y(2, 3);
        sout << x + y;
        // sout << x.operator+(y)
        REQUIRE(sout.str() == "7/6");
    }

    // Optional
    SUBCASE("1/2 + 2")
    {
        Rational<int> x(1, 2);
        Rational<int> r = x + 2;
        sout << r;
        REQUIRE(sout.str() == "5/2");
    }

    // Optional
    SUBCASE("2 + 1/2")
    {
        Rational<int> x(1, 2);
        Rational<int> r = 2 + x;
        sout << r;
        REQUIRE(sout.str() == "5/2");
    }
}

TEST_CASE("Rational: subtraction")
{
    ostringstream sout;

    SUBCASE("1/2 - 1/3")
    {
        Rational<int> r1(1, 2);
        Rational<int> r2(1, 3);

        sout << r1 - r2;

        REQUIRE(sout.str() == "1/6");
    }
}

TEST_CASE("Rational: multiplication")
{
    ostringstream sout;

    SUBCASE("1/2 * 1/3")
    {
        Rational<int> r1(1, 2);
        Rational<int> r2(1, 3);

        sout << r1 * r2;

        REQUIRE(sout.str() == "1/6");
    }
}

TEST_CASE("Rational: division")
{
    ostringstream sout;

    SUBCASE("1/2 : 1/3")
    {
        Rational<int> r1(1, 2);
        Rational<int> r2(1, 3);

        sout << r1 / r2;

        REQUIRE(sout.str() == "3/2");
    }

    SUBCASE("1/2 * 0/1")
    {
        Rational<int> r1(1, 2);
        Rational<int> r2(0, 1);

        REQUIRE_THROWS_AS(r1 / r2, runtime_error);
        REQUIRE_THROWS_WITH(r1 / r2, "Rational: division by zero");
    }

    SUBCASE("50/3 : 20/2")
    {
        Rational<int> r1(50, 3);
        Rational<int> r2(20, 2);

        sout << r1 / r2;

        REQUIRE(sout.str() == "5/3");
    }
}

TEST_CASE("comparisons")
{
    Rational<int> x(1, 2);
    Rational<int> y(1, 3);
    Rational<int> z(-10, -20);

    REQUIRE(x == z);
    REQUIRE(y != z);

    REQUIRE(x > y);
    REQUIRE(x >= y);
    REQUIRE(y < x);
    REQUIRE(y <= x);
}

TEST_CASE("Rational: input operator")
{
    SUBCASE("123/2")
    {
        istringstream sinp("123/2 42");

        Rational<int> r;
        int x;
        sinp >> r >> x;

        ostringstream sout;
        sout << r;
        REQUIRE(sout.str() == "123/2");
        REQUIRE(x == 42);
    }

    SUBCASE("123/-2")
    {
        istringstream sinp("123/-2");

        Rational<int> r;
        sinp >> r;

        ostringstream sout;
        sout << r;
        REQUIRE(sout.str() == "-123/2");
    }

    SUBCASE("one over two")
    {
        istringstream sinp("one over two");

        Rational<int> r;
        sinp >> r;

        REQUIRE(sinp.fail());

        REQUIRE(r.num() == 0);
        REQUIRE(r.den() == 1);
    }

    SUBCASE("1:2")
    {
        istringstream sinp("1:2");
        Rational<int> r;
        sinp >> r;

        REQUIRE(sinp.fail());
        REQUIRE(r.num() == 0);
        REQUIRE(r.den() == 1);
    }

    SUBCASE("1 /2")
    {
        istringstream sinp("1 /2");
        Rational<int> r;
        sinp >> r;

        REQUIRE(sinp.fail());
        REQUIRE(r.num() == 0);
        REQUIRE(r.den() == 1);
    }

    SUBCASE("1/ 2")
    {
        istringstream sinp("1/ 2");

        Rational<int> r;
        sinp >> r;

        REQUIRE(sinp.fail());
        REQUIRE(r.num() == 0);
        REQUIRE(r.den() == 1);
    }
}
