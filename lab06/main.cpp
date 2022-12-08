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

struct GreaterThan
{
    int mX;
    GreaterThan(int x)
        : mX(x)
    {
    }

    bool operator()(int n) const
    {
        return n > mX;
    }
};

struct CmpByGpa
{
    bool operator()(const Student &s1, Student &s2) const
    {
        return s1.mGpa < s2.mGpa;
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

void p0201()
{
    //vector<int> v = {3, 1, 20, 4, 7, 0, 5};

    //IsEven functor;
    //auto itV = find_if(begin(v), end(v), IsEven());
    //if (itV != end(v))
    //{
    //    cout << "position of the first even number is " << itV - begin(v) << endl;
    //    cout << "the number is " << *itV << endl;
    //}
    //else
    //{
    //    cout << "even numbers not found" << endl;
    //}

    vector<int> v2 = {3, 1, 20, 4, 7, 0, 5};

    //lambda expression;
    auto itV2 = find_if(begin(v2), end(v2), [](int n)
                        { return n % 2 == 0; });

    if (itV2 != end(v2))
    {
        cout << "position of the first even number is " << itV2 - begin(v2) << endl;
        cout << "the number is " << *itV2 << endl;
    }
    else
    {
        cout << "even numbers not found" << endl;
    }
}

void p0202()
{
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};

    //IsEven functor;
    auto it = auFindIf(begin(v), end(v), IsEven());
    if (it != end(v))
    {
        cout << "position of the first even number is " << it - begin(v) << endl;
        cout << "the number is " << *it << endl;
    }
    else
    {
        cout << "even numbers not found" << endl;
    }

    vector<int> v2 = {3, 1, 20, 4, 7, 0, 5};

    //lambda expression;
    auto itV2 = auFindIf(begin(v2), end(v2), [](int value)
                         { return value % 2 == 0; });

    if (itV2 != end(v2))
    {
        cout << "position of the first even number is " << itV2 - begin(v2) << endl;
        cout << "the number is " << *itV2 << endl;
    }
    else
    {
        cout << "even numbers not found" << endl;
    }
}

void p03()
{
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};

    cout << "Enter x: ";
    int x;
    cin >> x;

    auto it = find_if(begin(v), end(v), 
                        [x](int n) 
                        { return n > x; });

    if (it != end(v))
    {
        cout << *it << " found. Its index is " << it - begin(v) << endl;
    }
    else
    {
        cout << "even numbers not found" << endl;
    }

    auto it2 = find_if(begin(v), end(v), GreaterThan(x));
    if (it2 != end(v))
    {
        cout << *it2 << " found. Its index is " << it2 - begin(v) << endl;
    }
    else
    {
        cout << "even numbers not found" << endl;
    }
}

void p0401()
{
    vector<int> vc;
    int x;
                                   
    while (cin >> x)
    {
        vc.push_back(x);
    }

    auto it = min_element(begin(vc), end(vc));

    if (it != end(vc))
    {
        cout << "index of it: " << it - begin(vc) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}

void p0402()
{
    vector<int> vc;
    int x;

    while (cin >> x)
    {
        vc.push_back(x);
    }

    auto it = auMinElement(begin(vc), end(vc));

    if (it != end(vc))
    {
        cout << "index of it: " << it - begin(vc) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}

void p0501()
{
    vector<Student> students;
    string name;
    double gpa;

    while (cin >> name >> gpa)
    {
        students.emplace_back(name, gpa);
    }

    cout << "student with min name gpa" << endl;
    auto it = min_element(begin(students), end(students), [](Student s, Student min)
                          { return s.mGpa < min.mGpa; });

    if (it != end(students))
    {
        cout << "index: " << it - begin(students) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    cout << "student with min name (lexicographically)" << endl;
    auto it2 = min_element(begin(students), end(students), [](Student s, Student min)
                           { return s.mName < min.mName; });

    if (it2 != end(students))
    {

        cout << "index: " << it2 - begin(students) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}


void p0502()
{
    vector<Student> students;
    string name;
    double gpa;

    while (cin >> name >> gpa)
    {
        students.emplace_back(name, gpa);
    }

    cout << "student with min name gpa" << endl;
    auto it = auMinElement(begin(students), end(students), [](Student s, Student min)
                           { return s.mGpa < min.mGpa; });

    if (it != end(students))
    {
        cout << "index: " << it - begin(students) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    cout << "student with min name (lexicographically)" << endl;
    auto it2 = auMinElement(begin(students), end(students), [](Student s, Student min)
                            { return s.mName < min.mName; });

    if (it2 != end(students))
    {

        cout << "index: " << it2 - begin(students) << endl;
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
    // p0101();
    // p0102();

    // p0201();
    // p0202();

    //p03();

    //p0401();
    //p0402();

    //p0501();
    //p0502();
    
    // p06();
}