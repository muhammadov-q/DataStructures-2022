#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <utility>
#include <tuple>
#include <iomanip>

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

void p06()
{
    vector<Student> students;

    string name;
    double gpa;
    while (cin >> name >> gpa)
    {
        //students.push_back(Student(name, gpa));
        students.emplace_back(name, gpa);
    }

    cout << "-------" << endl;
    sort(begin(students), end(students), [](const Student &s1, const Student &s2)
         { return s1.mName < s2.mName; });

    cout << fixed << showpoint << setprecision(2);
    for (const auto &s : students)
    {
        cout << "{" << s.mName << ", " << s.mGpa << "}" << endl;
    }

    cout << "-------" << endl;
    sort(begin(students), end(students), [](Student &s1, const Student &s2) {return s1.mGpa > s2.mGpa; });

    for (const auto &s : students)
    {
        cout << "{" << s.mName << ", " << s.mGpa << "}" << endl;
    }
}


int main()
{
    //p0101();
    //p0102();

    p06();

}