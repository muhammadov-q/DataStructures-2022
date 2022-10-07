#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

char a[120][120];
int n, m, ans;

void solve()
{
    ans = 0;
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
    printf("%d\n", ans/2);
}

int main()
{
    iostream::sync_with_stdio(false);
    while(scanf("%d%d", &n, &m) != EOF)
    {   
        for (int i = 0; i < n; i++)
        {
            scanf("%s", a[i]);

        }
        solve();
    }
}