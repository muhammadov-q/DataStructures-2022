#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int solve(int a, int b)
{
    if (a > b) {
        swap(a, b);
    }

    int maxLength = 0;
    for (int i = a; i <= b; i++)
    {
        int cur = i;
        int nSteps = 1;
        while(cur != 1) 
        {
            if (cur % 2 != 0) 
            {
                cur = 3 * cur + 1;
            } else 
            {
                cur = cur / 2;
            }
        ++nSteps;
        }
        maxLength = max(nSteps, maxLength);
    }

    return maxLength;
}

int main()
{
    iostream::sync_with_stdio(false);

    for(int a, b; cin >> a >> b;) 
    {
        cout << a << " " << b << " " << solve(a, b) << "\n";
    }
}