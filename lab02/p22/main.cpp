#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int t;
    cin >> t;

    while(t--)
    {
        int count = 0;
        int n;
        cin >> n;
        vector<int> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j< i; j++)
            {
                if (v[i] >= v[j])
                {
                    count++;
                }
            }
        }
        cout << count << "\n";
    }
}