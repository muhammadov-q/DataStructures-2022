#include <bits/stdc++.h>

template <typename C>
int sz(const C &col) { return static_cast<int>(col.size()); }

using namespace std;

struct Freq
{
    char letter;
    int count;
};

Freq make_freq(char letter, int count)
{
    Freq a;
    a.letter = letter;
    a.count = count;

    return a;
}

int main()
{
    iostream::sync_with_stdio(false);

    int tc;
    cin >> tc;
    for (int test = 1; test <= tc; test++)
    {
        int row, col, impBytes, nonImpBytes;
        cin >> row >> col >> impBytes >> nonImpBytes;

        vector<Freq> vc;
        char letter;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> letter;
                auto it = lower_bound(vc.begin(), vc.end(), letter, [](Freq a, char w)
                                      { return a.letter < w; });

                if (it != vc.end())
                {
                    if (it->letter == letter)
                    {
                        it->count++;
                    }
                    else
                    {
                        Freq a = make_freq(letter, 1);
                        vc.insert(it, a);
                    }
                }
                else
                {
                    Freq a = make_freq(letter, 1);
                    vc.push_back(a);
                }
            }
        }

        sort(vc.begin(), vc.end(), [](Freq a, Freq b)
                { return a.count > b.count; });

        int freq = (*(vc.begin())).count;

        for (vector<Freq>::iterator a = vc.begin(); a < vc.end() - 1; a++)
        {
            if ((*a).count == (*(1 + a)).count)
            {
                freq += (*a).count;
            }
            else
            {
                break;
            }
        }
        
        int nfreq = row * col - freq;
        cout << "Case " << test << ": " << freq * impBytes + nfreq * nonImpBytes << endl;
    }
}
