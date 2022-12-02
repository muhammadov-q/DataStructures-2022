#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Skill
{
    string job;
    int salary;
};

int main()
{
    iostream::sync_with_stdio(false);

    int m, n;
    string word;
    cin >> m >> n;

    vector<Skill> v(m);
    for (int i = 0; i < m; i++)
    {
        cin >> v[i].job >> v[i].salary;
    }

    sort(v.begin(), v.end(), [](Skill a, Skill b)
        { return a.job < b.job; });

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        while (cin >> word && word != ".")
        {
            auto it = lower_bound(v.begin(), v.end(), word, [](Skill a, string w)
                                  { return a.job < w; });

            if (it != v.end())
            {
                if (it->job == word) //(*it).job
                {
                    sum += it->salary;
                }
            }
        }
        cout << sum << "\n";
    }
}