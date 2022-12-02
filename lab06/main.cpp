#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <utility>
#include <tuple>

#include "../au/algol.hpp"

using namespace std;

struct Student
{
    string mName;
    double mGpa;

    Student(const string &name, double gpa)
        : mName(name), mGpa(gpa)
    {
    }
};

// supporr call operator: T t; t()
struct IsEven
{
    bool operator()(int value) const
    {
        return value % 2 == 0;
    }
};

void p0101()
{
    int a[] = {3, 1, 20, 4, 7, 0, 5};
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};

    auto itA = find(begin(a), end(a), 20);
    if (itA != end(a))
    {
        cout << "position of 20 is " << itA - begin(a) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    auto itV = find(begin(v), end(v), -1);
    if (itV != end(v))
    {
        cout << "position of 20 is " << itV - begin(v) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}

void p0102()
{
    int a[] = {3, 1, 20, 4, 7, 0, 5};
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};

    auto itA = auFind(begin(a), end(a), 20);
    if (itA != end(a))
    {
        cout << "position of 20 is " << itA - begin(a) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    auto itV = auFind(begin(v), end(v), -1);
    if (itV != end(v))
    {
        cout << "position of 20 is " << itV - begin(v) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}

int main()
{
    //p0101();
    p0102();
}