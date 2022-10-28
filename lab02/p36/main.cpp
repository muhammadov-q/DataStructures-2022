#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        cout << "Case " << t << ": ";
        string line;
        cin >> line;
        
        int pos = 0, count = 0;
        char letter = line[pos];
        pos++;
        for (; pos < sz(line); pos++)
        {
            if (isalpha(line[pos]))
            {
                cout << string(count, letter);
                count = 0;
                letter = line[pos];
            }
            if (isdigit(line[pos]))
            {
                count = count * 10 + line[pos] - '0';   
            }
        }
        cout << string(count, letter) << '\n';
    }
}