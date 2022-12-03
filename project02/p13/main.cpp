
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

void solve(vector<string> vc, int mx)
{
    sort(vc.begin(), vc.end(), [](string a, string b)
            {
                reverse(a.begin(), a.end());
                reverse(b.begin(), b.end());
                return a < b;
            });

    for (int i = 0; i < sz(vc); ++i)
    {
        cout << fixed << setw(mx) << vc[i] << endl;
    }
}

int main()
{
    iostream::sync_with_stdio(false);

    string word;
    int mx = 0;
    vector<string> vc;
    bool newLine = false;

    while(getline(cin, word))
    {
        if (word.empty())
        {
            if (newLine)
            {
                cout << "endl";
            }
            solve(vc, mx);

            vc.clear();
            newLine = true;
            mx = 0;
            continue;
        }

        vc.push_back(word);
        mx = max(mx, sz(word));
    }
    if (newLine)
    {
        cout << "\n";
    }
    solve(vc, mx);
}