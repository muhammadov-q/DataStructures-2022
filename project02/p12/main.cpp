#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int nTests;
    cin >> nTests;
    for (int test = 0; test < nTests; test++)
    {
        int nPeople;
        cin >> nPeople;

        vector<pair<string, string>> v;
        string name, value, classes;
        for (int i = 0; i < nPeople; i++)
        {
            cin >> name;
            name.pop_back();

            cin >> value >> classes;
            
            string val = "";
            string typeOfClass;
            for (int j = 0; j < sz(value); j++)
            {
                if (value[j] == '-')
                {
                    if (typeOfClass == "upper")
                    {
                        val += "3";
                    }
                    else if (typeOfClass == "middle")
                    {
                        val += "2";
                    }
                    else
                    {
                        val += "1";
                    }
                    typeOfClass = "";
                    continue;
                }
                typeOfClass += value[j];
            }

            if (typeOfClass == "upper")
            {
                val += "3";
            }
            else if (typeOfClass == "middle")
            {
                val += "2";
            }
            else
            {
                val += "1";
            }

            reverse(begin(val), end(val));
            while (sz(val) < 10)
            {
                val += "2";
            }

            v.emplace_back(val, name);
        }

        stable_sort(v.begin(), v.end(), [](pair<string, string> a, pair<string, string> b)
                    {
                        if (a.first == b.first)
                        {
                            return a.second < b.second;
                        }
                        return a.first > b.first;
                    });

        for (int i = 0; i < nPeople; i++)
        {
            cout << v[i].second << endl; 
        }

        cout << "==============================\n"; 
    } 
}