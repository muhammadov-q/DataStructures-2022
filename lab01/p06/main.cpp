#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include <vector>

using namespace std;

struct Student
{
    int mID;
    int mBirthYear;
    Student(int ID, int birthYear)
        : mID(ID), mBirthYear(birthYear)
    {
    }

    int getID() const
    {
        return mID;
    }
};

template <typename C>
string containerToStr(const C &c)
{
    ostringstream sout;
    bool isFirst  = true;
    sout << "{";
    for (const auto &e : c)
    {
        if (!isFirst)
        {
            sout << ", ";
        }
        sout << e;
        isFirst = false;
    }
    sout << "}";

    return sout.str();
}

TEST_CASE("Default constructor")
{
    vector<int> v;

    REQUIRE(v.empty());
    REQUIRE(v.size() == 0);
}

TEST_CASE("constructor with size")
{
    vector<int> v = {1, 2, 3, 4, 5};

    REQUIRE(!v.empty());
    REQUIRE(containerToStr(v) == "{1, 2, 3, 4, 5}");
    REQUIRE(v.size() == 5);
}

TEST_CASE("constructor with size and initial value")
{
    vector<int> v = {1, 2, 3, 4, 5};
    REQUIRE(containerToStr(v) == "{1, 2, 3, 4, 5}");
    
    v[0] = 9;
    v[1] = 10;

    REQUIRE(containerToStr(v) == "{9, 10, 3, 4, 5}");
    REQUIRE(v.size() == 5);
}

TEST_CASE("copy constructor")
{
    vector<int> v = {1, 2, 3, 4, 5};

    vector<int> v2 = v; // copy constructor

    REQUIRE(v.size() == 5);
    REQUIRE(containerToStr(v) == "{1, 2, 3, 4, 5}");

    v[0] = 1000;
    v2[4] = 42;

    REQUIRE(containerToStr(v) == "{1000, 2, 3, 4, 5}");
    REQUIRE(containerToStr(v2) == "{1, 2, 3, 4, 42}");
    
}

TEST_CASE("assignment operator")
{
    vector<int> v = {1, 2, 3, 4, 5};
    v[0] += 2; //assignment operator

    REQUIRE(containerToStr(v) == "{3, 2, 3, 4, 5}");
}

TEST_CASE("move constructor")
{
    vector<int> v = {1, 2, 3, 4, 5};

    vector<int> v2 = v; // assigment is same with copy constructor

    REQUIRE(v.size() == 5);
    REQUIRE(containerToStr(v) == "{1, 2, 3, 4, 5}");

    v[0] = 100;
    v2[4] = 42;

    REQUIRE(containerToStr(v) == "{100, 2, 3, 4, 5}");
    REQUIRE(containerToStr(v2) == "{1, 2, 3, 4, 42}");
}

TEST_CASE("move assignment")
{
    vector<int> v;
    vector<int> v2 = {1, 2, 3, 4, 5};

    REQUIRE(v.empty());
    REQUIRE(v2.size() == 5);

    v = move(v2); // move assignment

    REQUIRE(v2.empty());
    REQUIRE(containerToStr(v) == "{1, 2, 3, 4, 5}");
}

TEST_CASE("subscript operator")
{
    vector<int> v = {1};

    REQUIRE(containerToStr(v) == "{1}");

    v[0] = 2; // changes value 1 to 2 with the use of subcript operator
    
    REQUIRE(containerToStr(v) == "{2}");
}

TEST_CASE("method at(index), exception")
{
    vector<int> v;
    v.push_back(1);

    REQUIRE(v.at(0) == 1); //v.at(1) it is out of bounds...
    REQUIRE_THROWS_AS(v.at(11), logic_error);
}

TEST_CASE("push_back")
{
    vector<int> v;
    
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
   
    REQUIRE(v.size() == 5);
    REQUIRE(containerToStr(v) == "{1, 2, 3, 4, 5}");
    REQUIRE(v.capacity() == 8);
}

TEST_CASE("pop_back method")
{
    vector<int> v = {1, 2, 3 , 4, 5};

    REQUIRE(containerToStr(v) == "{1, 2, 3, 4, 5}");
    REQUIRE(v.size() == 5);
    
    v.pop_back();
    v.pop_back();
    v.pop_back();
   
    REQUIRE(containerToStr(v) == "{1, 2}");
    REQUIRE(v.capacity() == 5);
}

TEST_CASE("auto element : container")
{
    vector<int> v = {1, 2, 3 , 4, 5};

    REQUIRE(containerToStr(v) == "{1, 2, 3, 4, 5}");

    for (auto &c : v)
    {
        c++; //adding 1 to each element of vector v;
    }

    REQUIRE(containerToStr(v) == "{2, 3, 4, 5, 6}");
}

TEST_CASE("methods front(), back();")
{
    vector<int> v = {1, 2, 3 , 4, 5};

    REQUIRE(v.front() == 1); // prints the first element of array
    REQUIRE(v.back() == 5); // prints the last element of aray

    v.front() = 10;
    REQUIRE(v[0] == 10);

    v.back() = 100;
    REQUIRE(v[4] == 100); 
}

TEST_CASE("vector< T>::iterator, operators")
{
    vector<int> v = {10, 5, 2, 3};

    // vector<int> ::iterator it = v.begin();

    auto it = v.begin();

    REQUIRE(*it == 10);

    ++it;
    REQUIRE(*it == 5);

    REQUIRE(*++it == 2);
    REQUIRE(*it++ == 2);
    REQUIRE(*it == 3);

    auto it2 = v.end();
    REQUIRE(it != it2);
    REQUIRE(it < it2);

    --it2;
    REQUIRE(*it2 == 3);

    it2 -= 2;

    REQUIRE(*it2 == 5);

    REQUIRE(it2 - v.begin() == 1);

    vector<Student> s = {{1001, 2003}, {1002, 2004}};

    auto it3 = s.begin();

    REQUIRE((*it3).mBirthYear == 2003);
    REQUIRE(it3->mBirthYear == 2003);
    REQUIRE(it3->getID() == 1001);
}

TEST_CASE("methods insert(it, value), insert(it, beg, end)")
{
    vector<int> v = {1, 2, 3, 4, 5};
    REQUIRE(containerToStr(v) == "{1, 2, 3, 4, 5}");

    vector<int>::iterator it;
    it = v.begin();

    v.insert(it, 100);
    REQUIRE(containerToStr(v) == "{100, 1, 2, 3, 4, 5}");


    v.insert(v.begin() + 3, 90);
    REQUIRE(containerToStr(v) == "{100, 1, 2, 90, 3, 4, 5}");

    v.insert(v.end() - 1, 222);
    REQUIRE(containerToStr(v) == "{100, 1, 2, 90, 3, 4, 222, 5}");
}

TEST_CASE("methods erase(it), erase(beg, end)")
{
    vector<int> v{ 1, 2, 3, 4, 5 };
    vector<int>::iterator iter1, iter2;
    
    REQUIRE(containerToStr(v) == "{1, 2, 3, 4, 5}");

    iter1 = v.begin();
    v.erase(iter1); // erase first element of the vector
    REQUIRE(containerToStr(v) == "{2, 3, 4, 5}");
    
    iter1 = v.begin();
    iter2 = v.end();
    v.erase(iter1, iter2); // erase all elements from begin() to end()

    REQUIRE(v.empty());
}

TEST_CASE("constructor vector(beg, end)")
{
    vector<int> v = {1, 2, 3 , 4, 5};
    vector<int> v2(begin(v), end(v)); //assign every element of v to v2

    REQUIRE(containerToStr(v) == "{1, 2, 3, 4, 5}");
    REQUIRE(containerToStr(v2) == "{1, 2, 3, 4, 5}");
}

TEST_CASE("std::reverse algorithm")
{
    vector<int> v = {1, 2, 3 , 4, 5};

    REQUIRE(containerToStr(v) == "{1, 2, 3, 4, 5}");

    reverse(v.begin(), v.end());
    REQUIRE(containerToStr(v) == "{5, 4, 3, 2, 1}");

}

TEST_CASE("std::binary_search algorithm")
{
    vector<int> v = {1, 2, 3 , 4, 5};

    REQUIRE(binary_search(v.begin(), v.end(), 3));
    REQUIRE(!binary_search(v.begin(), v.end(), 11));
}

TEST_CASE("std::min_element algorithm")
{
    vector<int> v = {5, 4, 3, 1, 2, 12, 9};
    vector<int>::iterator result = min_element(v.begin(), v.end());
    int ans = distance(v.begin(), result); //returns index of the smallest element

    REQUIRE(v[ans] == 1); 
}

TEST_CASE("std::max_element algorithm")
{
    vector<int> v = {5, 4, 3, 1, 2, 12, 9};
    vector<int>::iterator result = max_element(v.begin(), v.end());
    int ans = distance(v.begin(), result); //returmns index of the largest element 

    REQUIRE(v[ans] == 12); 
}
