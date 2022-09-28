#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    const int size = 16;
    string song[size] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to",
    "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};

    int numOfPeople;
    cin >> numOfPeople;

    vector<string> people(numOfPeople);
    for (int i; i < numOfPeople; i++)
    {
        cin >> people[i];
    }

    bool isOver = false;
    for (int person = 0, cWord = 0; cWord < size || !isOver; ++person, ++cWord)
    {
        cWord %= size;
        cout << people[person] << ": " << song[cWord] << "\n";
        
        if (person + 1 == numOfPeople)
        {
            isOver = true;
            person = -1;
        }
    }
}