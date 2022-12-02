#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int n, m;
    while (cin >> n >> m && (n + m))
    {
        vector<int> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
            

        //sorting with functor(lambda)
        sort(v.begin(), v.end(), [&](int a, int b)
             {
                 if (a % m == b % m)
                 {
                     if (abs(a % 2) == 0 && abs(b % 2) != 0)
                     {
                        return false;
                     }
                     if (abs(a % 2) != 0 && abs(b % 2) == 0)
                     {
                         return true;
                     }
                     if (abs(a % 2) == 1 && abs(b % 2) == 1)
                     {
                        return a > b;
                     }  
                     if (abs(a % 2) == 0 && abs(b % 2) == 0)
                     {
                        return a < b;
                     }
                 }
                 return a % m < b % m;
             });

        cout << n << " " << m << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << "\n";
        }
    }

    cout << "0 0" << endl;
}