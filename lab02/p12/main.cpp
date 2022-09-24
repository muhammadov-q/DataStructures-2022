#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    long long num;
    int sum;
    for (;;)
    {
        cin >> num;
        if (num == 0) break;

        while (num / 10 != 0)
        {
           sum = 0;
           while (num!=0)
           {
                sum = sum + num%10;
                num /= 10;
           } 
           num = sum;
        }

        cout << num << "\n";
    }
}