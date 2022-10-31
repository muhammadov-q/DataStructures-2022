#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    
    int numOfPeople;
    cin >> numOfPeople;

    string song[] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to",
    "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};

    vector<string> people(numOfPeople);
    for (int i; i < numOfPeople; i++)
    {
        cin >> people[i];
    }

    int ln = 16 * ceil((double) numOfPeople / 16);
    for (int i = 0; i < ln; i++)
    {
        cout << people[(i%numOfPeople)] << ": " << song[i%16] << endl;
    }
}