#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int tc = 0;
    cin >> tc;

    for (int t = 1; t <= tc; ++t)
    {
        string url[10];
        int value[10];
        int maximum = 0;
        for (int j = 0; j < 10; j++){
			cin >> url[j] >> value[j];
			maximum = max(value[j], maximum);
		}

	    cout << "Case #" << t << ":\n";
		for (int i = 0; i < 10; i++)
			if( value[i] == maximum )
				cout << url[i] << "\n";
    }
}