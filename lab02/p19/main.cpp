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
        int male = count(str.begin(), str.end(), 'M');
        int female = count(str.begin(), str.end(), 'F');
        if (male == female && (male > 1 && female > 1))
        {
            cout << "LOOP" << endl;
        }
        else
        {
            cout << "NO LOOP" << endl;
        }
    }
}
