#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int x;
    cin >> x;

    for (int tc = 1; tc <= x; tc++)
    {
        int n;
        cin >> n;
        vector<int> red, blue;

        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;

            string value = "";
            for (int j = 0; j < sz(str); j++)
            {
                if (str[j] == 'R')
                {
                    red.push_back(stoi(value));
                    value = "";
                    continue;
                }
                else if (str[j] == 'B')
                {
                    blue.push_back(stoi(value));
                    value = "";
                    continue;
                }
                value += str[j];
            }
        }

        sort(blue.begin(), blue.end(), greater<int>());
        sort(red.begin(), red.end(), greater<int>());

        vector<int> segment;
        for (int i = 0; i < min(sz(red), sz(blue)); i++)
        {
            segment.push_back(blue[i] + red[i] - 2);
        }
            
        cout << "Case #" << tc << ": " << accumulate(segment.begin(), segment.end(), 0) << endl;
    }
}