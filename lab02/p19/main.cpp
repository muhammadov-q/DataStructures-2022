#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int T; cin >> T;
    string str; getline(cin, str);
    while (T--) {
        getline(cin, str);
        istringstream sinp(str);
        int m = 0, f = 0, mf = 0, pieces = 0;
        bool isLoop = false;
        while (sinp.good()) {
            pieces++;
            sinp >> str;
            if (!str.compare("MM")) 
            {
                m += 2;
            }
            else if (!str.compare("FF")) 
            {
                f += 2;
            }
            else {
                mf++;
            }
        } if (pieces > 1) 
        {
            if (mf > 1) 
            {
                m++;
                f++;
            }
            if (m == f) 
            {
                isLoop = true;
            }
        }
        cout << (isLoop ? "LOOP" : "NO LOOP") << endl;
    }
}
