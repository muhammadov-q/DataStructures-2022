#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int tc = 0;
   for(int r, n; cin >> r >> n;)  
    {
        if (r + n == 0) 
        {
            break;
        }

        int answer = (r-n)/n + ((r-n)%n != 0 && r >= n);
        cout << "Case " << ++tc << ": ";

        if (answer > 26)
        {
            cout << "impossible" << "\n";
        }
        else
        {
            cout << answer << "\n";
        }
    }
}