#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int tcases;
    cin >> tcases;   
                                               
    while(tcases--) {
        int nstores;
        cin >> nstores;
        int mx = 0, mn = 100;
        for (int i = 0 ; i < nstores ; ++i) {
            int nposition;
            cin >> nposition;
            mx = max(mx, nposition);
            mn = min(mn, nposition);
        }
        cout << 2 * (mx - mn) << "\n";
    }
}