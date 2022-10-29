#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int b = 0, g = 1, c = 2;
    int s1, s2, s3;
    vector<int> v1(3);
    vector<int> v2(3);
    vector<int> v3(3);
    vector<vector<int>> ps = {{b, g, c}, {b, c, g}, {c, b, g}, {c, g, b}, {g, c ,b}, {g, b, c}};
    string color = "BGC";

    while(cin >> v1[0] >> v1[1] >> v1[2])
    {
        for (int i = 0; i < 3; i++)
        {
            cin >> v2[i];
        }

        for (int i = 0; i < 3; i++)
        {
            cin >> v3[i];
        }

        vector<int> ans;
        int sum = 0, mn = 9999999;
        for(auto p : ps)
        {
            s1 = v1[p[b]] + v2[p[b]];
            s2 = v1[p[g]] + v3[p[g]];
            s3 = v2[p[c]] + v3[p[c]];
            sum = s1 + s2 + s3;
            if (sum < mn)
            {
                mn = sum;
                ans = p;
            }
        }

        for(int a : ans)
        {
            cout << color[a];
        }

        cout << " " << mn << "\n";
    }

}