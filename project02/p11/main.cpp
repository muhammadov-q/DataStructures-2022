#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

string to_lower(string a)
{
    for (int i = 0; i < sz(a); ++i)
    {
        a[i] = tolower(a[i]);
    }

    return a;
}

int main()
{
    iostream::sync_with_stdio(false);
    int row, col;
    bool newLine = false;

    while(cin >> row >> col && !(row + col == 0))
    {
        if (newLine)
        {
            cout << "\n";
        }

        vector<string> vc(row);
        for (int i = 0; i < row; ++i)
        {
            cin >> vc[i];
        }

        vector<string> vs(col);
        for (int i = 0; i < col; ++i)
        {
            for (int j = 0; j < row; ++j)
            {
                vs[i] += vc[j][i];
            }
        }

        stable_sort(vs.begin(), vs.end(), [](string a, string b)
                        { return to_lower(a) < to_lower(b); });

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout << vs[j][i];
            }
            cout << "\n";
        }

        newLine = true;
    }
}
