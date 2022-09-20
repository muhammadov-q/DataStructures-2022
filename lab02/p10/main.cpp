#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int tcases;
    cin >> tcases;

    for (int i = 1; i <= tcases; ++i) {
        int nwalls;
        cin >> nwalls;
        int lcount = 0, hcount = 0, checker = 0;
        for (int j = 0; j < nwalls; ++j) {
            int height;
            cin >> height;
            if (j == 0) {
                checker == height;
            } else {
                if (height > checker) {
                    checker = height;
                    ++hcount;
                } else if (height < checker) {
                    checker = height;
                    ++lcount;
                }
            }
        }
        cout << "Case " << i << ": " << hcount << " " << lcount << "\n"; 
    }
}