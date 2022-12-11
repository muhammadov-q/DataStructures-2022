#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Pair
{
    int mAscii;
    int mValue;

    Pair(int &a, int &b)
        : mAscii(a), mValue(b)
    {
    }

    bool operator==(int ch)
    {
        return mAscii == ch;
    }
};

int main()
{
    iostream::sync_with_stdio(false);

    string line;
    int count = 0;
    while (getline(cin, line))
    {
        if (count != 0)
        {
            cout << endl;
        }

        vector<Pair> v;
        for (int i = 0; i < sz(line); i++)
        {
            auto it = find(begin(v), end(v), line[i]);
            if (it == end(v))
            {
                int a = line[i];
                int b = 1;
                v.emplace_back(a, b);
            }
            else
            {
                it->mValue++;
            }
        }

        sort(begin(v), end(v), [](Pair p1, Pair p2)
             {
                if (p1.mValue == p2.mValue)
                {
                    return p2.mAscii < p1.mAscii;
                }
                return p1.mValue < p2.mValue;
             });
             
        for (auto t : v)
        {
            cout << t.mAscii << " " << t.mValue << "\n";
        }

        count = 1;
    }
}