#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct SpecialString
{
    string mDna;
    int mDiff;

    SpecialString(string &dna, int &diff)
        : mDna(dna), mDiff(diff)
    {
        for (int i = 0; i < sz(dna) - 1; i++)
        {
            for (int j = i + 1; j < sz(dna); j++)
            {
                if (dna[i] > dna[j])
                {
                    mDiff++;
                }
            }
        }
    }
};

int main()
{
    iostream::sync_with_stdio(false);

    int nTests;
    cin >> nTests;
    for (int test = 0; test < nTests; test++)
    {
        if (test)
        {
            cout << "\n";
        }

        int length, nStrings;
        string dna;
        cin >> length >> nStrings;

        vector<SpecialString> v;

        int diff;
        for (int i = 0; i < nStrings; i++)
        {
            cin >> dna;
            v.emplace_back(dna, diff);
        }

        stable_sort(v.begin(), v.end(), [](SpecialString a, SpecialString b)
                    { return a.mDiff < b.mDiff; });

        for (int i = 0; i < nStrings; i++)
        {
            cout << v[i].mDna << "\n";
        }
    }
}