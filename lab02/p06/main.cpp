#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int tc, p1, p2, p3, tmp;
    cin >> tc;

    for(int i = 0; i < tc; ++i)
    {
        cin >> p1 >> p2 >> p3;
        if(p1 > p3)
            tmp = p1, p1 = p3, p3 = tmp;
        if(p2 > p3)
            tmp = p2, p2 = p3, p3 = tmp;
        if(p1 > p2)
            tmp = p1, p1 = p2, p2 = tmp;
        cout << "Case " << i << ": " << p2 << "\n";
    }
}