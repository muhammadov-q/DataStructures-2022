#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    char a[120][120];
    for (int n, m; cin >> n >> m;)
    {   
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        bool in = false;
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '/' || a[i][j] == '\\')
            {
                ++ans;
                in =! in;
            } else if (in)
            {
                ans += 2;
            }
        }
    }
    cout << ans/2 << endl;
    }
}
