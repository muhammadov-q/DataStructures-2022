#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int sumOfLetters(string name) 
{
    int sum = 0;
    for (auto c : name)
      {
        if (isalpha(c))
        { 
            if (islower(c))
            {
                sum += c - 'a' + 1;
            }
            else if (isupper(c))
            {
                sum += c - 'A' + 1;
            }
        }
      }

    return sum;
}

int sumOfDigits(int num)
{
    if (num %9 == 0)
    {
        num = 9;
    } 
    else 
    {
        num %= 9;
    } 
    return num;
}

int main()
{
    iostream::sync_with_stdio(false);
    for (;;)
    {
        if (cin.eof()) break;
        string name1, name2;
        getline(cin, name1);
        getline(cin, name2);
        int first = sumOfDigits(sumOfLetters(name1));
        int second = sumOfDigits(sumOfLetters(name2));

        cout << fixed << setprecision(2);
        if (first < second)
            cout << (first * 100.0 / second) << " %" <<  "\n";   
        else
            cout << (second * 100.0 / first) << " %" << "\n";
    }
}
