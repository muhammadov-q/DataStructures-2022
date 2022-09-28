#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

void solve(int &n, int &sum, int &count)
{
    sum = 0;
    count = 0;

    while(n != 0)
    {
        sum += n%10;
        ++count;
        n /= 10;
    }
}

int main()
{
    iostream::sync_with_stdio(false);
    int num;
    for (;;)
    {
        cin >> num;
        if (num == 0) break;

        int sumOfDigits;
        int countOfDigits;
        do 
        {
            solve(num, sumOfDigits, countOfDigits);
            num = sumOfDigits;
        } while (countOfDigits != 1);

        cout << num << "\n";

        // while (num / 10 != 0)
        // {
        //    sum = 0;
        //    while (num!=0)
        //    {
        //         sum = sum + num%10;
        //         num /= 10;
        //    } 
        //    num = sum;
        // }

        // cout << num << "\n";
    }
}