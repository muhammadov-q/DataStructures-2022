#include <iostream>
#include <utility>
#include <string>

using namespace std;

template<typename T>
void auSwap(T &x, T &y)
{
    T t = x;
    x = y;
    y = t;
}

void badSwap(int x, int y)
{
    int t = x;
    x = y;
    y = t;
}

void goodSwap01(int *p, int *q)
{
    int t = *p;
    *p = *q;
    *q = t;
}

//by reference
void goodSwap02(int &x, int &y)
{
    int t = x;
    x = y;
    y = t;
}

int main()
{
    cout << "1st int: ";
    int a;
    cin >> a;

    cout << "2nd int: ";
    int b;
    cin >> b;

    cout << "std::swap" << endl;
    cout << "Before swap a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "After swap a = " << a << ", b = " << b << endl;

    cout << "badSwap:" << endl;
    cout << "Before swap a = " << a << ", b = " << b << endl;
    badSwap(a, b);
    cout << "After swap a = " << a << ", b = " << b << endl;

    cout << "goodSwap01:" << endl;
    cout << "Before swap a = " << a << ", b = " << b << endl;
    goodSwap01(&a, &b);
    cout << "After swap a = " << a << ", b = " << b << endl;

    cout << "goodSwap02:" << endl;
    cout << "Before swap a = " << a << ", b = " << b << endl;
    goodSwap02(a, b);
    cout << "After swap a = " << a << ", b = " << b << endl;

    cout << "general swap for doubles:" << endl;
    double d1 = 2.34;
    double d2 = 1.45;
    cout << "Before swap d1 = " << d1 << ", d2 = " << d2 << endl;
    auSwap(d1, d2);
    cout << "After swap d1 = " << d1 << ", d2 = " << d2 << endl;

    cout << "general swap for string:" << endl;
    string s1 = "hello";
    string s2 = "world";
    cout << "Before swap s1 = " << s1 << ", s2 = " << s2 << endl;
    auSwap(s1, s2);
    cout << "After swap s1 = " << s1 << ", s2 = " << s2 << endl;
}