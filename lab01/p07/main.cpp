#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

TEST_CASE("default constructor")
{
    string s;
    REQUIRE(s.empty());
    REQUIRE(s.length() == 0);
}

TEST_CASE("constructor with size and initial value")
{
    string s;
    REQUIRE(s.empty());

    s = "Hello";
    REQUIRE(s.length() == 5);
}

TEST_CASE("copy constructor")
{
    string s = "hello";
    string s2 = s; //copy constructor
    REQUIRE(s.length() == 5);
    REQUIRE(s == "hello");

    s2 = "hello wolrd";

    REQUIRE(s == "hello");
    REQUIRE(s2 == "hello wolrd");
}

TEST_CASE("assignment operator")
{
    string s = "hello";
    string s2 = "world";
    
    REQUIRE(s == "hello");

    s = s2; // Assigns s2 to s1
    REQUIRE(s == "world");
    REQUIRE(s2 == "world");
}

TEST_CASE("move constructor")
{
    string s = "hello";
    string s2;
    REQUIRE(s.length() == 5);
    REQUIRE(s2.empty());

    s2 = s; //move constructor
    s = "world";
    REQUIRE(s == "world");
    REQUIRE(s2 == "hello");
}

TEST_CASE("move assignment")
{
    string s = "hello";
    string s2;
    REQUIRE(s.length() == 5);
    REQUIRE(s2.empty());

    s2 = move(s); //move assignment 
    s = "world";
    REQUIRE(s == "world");
    REQUIRE(s2 == "hello");
}

TEST_CASE("subscript operator")
{
    string str = "hello";
    REQUIRE(str == "hello");

    str[0] = 'H'; //subscript operator
    REQUIRE(str == "Hello");
    
}

TEST_CASE("method at(index), exception")
{
    string str;
    str.push_back('h');

    REQUIRE(str.at(0) == 'h'); //str.at(1) it is out of bounds...
    REQUIRE_THROWS_AS(str.at(1), out_of_range);
}

TEST_CASE("push_back method")
{
    string str;
    str.push_back('h');
    str.push_back('e');
    str.push_back('l');
    str.push_back('l');
    str.push_back('o');

    REQUIRE(str == "hello");

    str.push_back('!');
     REQUIRE(str == "hello!");
}

TEST_CASE("pop_back method")
{
   string str = "helloo";
   REQUIRE(str == "helloo");

   str.pop_back();
   str.push_back('!');
   REQUIRE(str == "hello!");
}

TEST_CASE("+, += operators")
{
   string s = "hello";
   string s2 = " world";

   REQUIRE(s + s2 == "hello world");

   s += s2;
   REQUIRE(s2 == " world");
   REQUIRE(s == "hello world");

}

TEST_CASE("comparison operators")
{
   string s = "hi";
   string s2 = "hello";

   REQUIRE(s != s2);
   REQUIRE(s.length() < s2.length());
   REQUIRE(s.compare(s2) != 0); //compare method (returns boolean value)

   s = s2;
   REQUIRE(s == s2);
}

TEST_CASE("(auto &c : str) statement")
{
    string str = "hello";
    
    ostringstream sout;
    for (auto &c : str)
    {
        sout << c; //we get access to every element of string;
    }
    REQUIRE(sout.str() == "hello");
    REQUIRE(str == "hello");
}

TEST_CASE("methods front(), back();")
{
    string str = "xell_";
    REQUIRE(str.front() == 'x'); // prints the first element of array
    REQUIRE(str.back() == '_'); // prints the last element of aray

    str.front() = 'h';
    REQUIRE(str == "hell_");

    str.back() = 'o';
    REQUIRE(str == "hello"); 
}

TEST_CASE("methods substr(index, length), find(char ch)")
{
    string str = "one_two_three_four_five";
    string sbtr = str.substr(8, 5);
    REQUIRE(sbtr == "three");
    REQUIRE(str == "one_two_three_four_five");

    string str2= "c++ is the best programming language";    
    int position = str2.find("programming");  //it finds the index of the element
    REQUIRE(position == 16);
}

TEST_CASE("std::string::iterator, operators")
{
   vector<string> v = {"hello", "world", "C++", "language"};

    // vector<string> ::iterator it = v.begin();

    auto it = v.begin();

    REQUIRE(*it == "hello");

    ++it;
    REQUIRE(*it == "world");

    REQUIRE(*++it == "C++");
    REQUIRE(*it++ == "C++");
    REQUIRE(*it == "language");

    auto it2 = v.end();
    REQUIRE(it != it2);
    REQUIRE(it < it2);

    --it2;
    REQUIRE(*it2 == "language");

    it2 -= 2;
    REQUIRE(*it2 == "world");

    REQUIRE(it2 - v.begin() == 1);

    vector<string> str = {"hello", "world"};
    auto itr = str.begin();
    REQUIRE(*itr == "hello");

    itr->push_back('!'); //similiar dot (.) operator
    REQUIRE(*itr == "hello!");
}

TEST_CASE("method insert(index, length, char);")
{
   string str1 = "Hello World!";
   string str2 = "C++ ";

   REQUIRE(str1 == "Hello World!");

   str1.insert(6, str2);
   REQUIRE(str1 == "Hello C++ World!");
}

TEST_CASE("methods erase(index, length);")
{
    string str = "Hello World!";
    REQUIRE(str == "Hello World!");

    str.erase(1); // Deletes all characters except first one
    REQUIRE(str == "H");

    string str2 = "hello_world_c++";
    str2.erase(5, 6); //delets from 5 with lenght 6;
    REQUIRE(str2 == "hello_c++");
}

TEST_CASE("constructor string(beg, end);")
{
    string str = "hello world";
    
    ostringstream sout;
    for(string::iterator itr = str.begin(); itr!=str.end(); ++itr)
    {
        sout << *itr; 
    }  
     
    REQUIRE(sout.str() == "hello world");
}

TEST_CASE("std::reverse algorithm")
{
   string str = "hello world";
   REQUIRE(str == "hello world");

   reverse(str.begin(), str.end());
   REQUIRE(str == "dlrow olleh");
}

TEST_CASE("std::sort algorithm")
{
    string str = "bcda";
    REQUIRE(str == "bcda");

    sort(str.begin(), str.end()); //sorting algorithm
    REQUIRE(str == "abcd");
}

TEST_CASE("std::binary_search algorithm")
{
    string arr[] = { "I", "Love", "C++", "Prpogramming", "Language"};
 
    // Find size of array arr
    int size = sizeof(arr) / sizeof(arr[0]);

    //sorting for using binary search
    sort(arr, arr + size); 

    string str1 = "C++";
    string str2 = "For";

    REQUIRE(binary_search(arr, arr + size, str1));
    REQUIRE(!binary_search(arr, arr + size, str2));
}

TEST_CASE("std::min_element algorithm")
{
    vector<string> v = {"zzzzzzz", "hi", "mmmmmmm", "kkkkk", "ppp"};
    REQUIRE(v.size() == 5);

    vector<string>::iterator result = min_element(v.begin(), v.end());
    int ans = distance(v.begin(), result); //returns index of the smallest element

    REQUIRE(v[ans] == "hi"); 
}

TEST_CASE("std::max_element algorithm")
{
   vector<string> v = {"zzzzzzzzzz", "hi", "mmmmmmm", "kkkkk", "ppp"};
    REQUIRE(v.size() == 5);

    vector<string>::iterator result = max_element(v.begin(), v.end());
    int ans = distance(v.begin(), result); //returns index of the largest element

    REQUIRE(v[ans] == "zzzzzzzzzz"); 
}