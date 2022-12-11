#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Freq
{
    char mLetter;
    int mCount;

    Freq(char letter, int count)
        : mLetter(letter), mCount(count)
    {
    }
};

bool operator==(Freq const &a, char const &b)
{
    return a.mLetter == b;
}

int main()
{
    iostream::sync_with_stdio(false);
    int nTests;
    cin >> nTests;

    for (int test = 1; test <= nTests; test++)
    {
        int col, row, import, nonImport;
        cin >> col >> row >> import >> nonImport;
        vector<Freq> frequences;

        for (int i = 0; i < col; i++)
        {
            string line;
            cin >> line;

            for (int j = 0; j < row; j++)
            {
                auto it = find(begin(frequences), end(frequences), line[j]);
                if (it == end(frequences))
                {
                    frequences.push_back(Freq(line[j], 1));
                }
                else
                {
                    it->mCount++;
                }
            }
        }

        sort(begin(frequences), end(frequences), [](Freq a, Freq b)
            {
                return a.mCount < b.mCount;
            });

        int maxVal = (end(frequences) - 1)->mCount;

        int result = 0;
        auto k = begin(frequences);
        for (; k != end(frequences); k++)
        {
            if (k->mCount == maxVal)
            {
                result += ((k->mCount) * import);
            }
            else
            {
                result += ((k->mCount) * nonImport);
            }
        }

        cout << "Case " << test << ": " << result << '\n';
    }
}