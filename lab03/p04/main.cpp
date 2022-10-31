#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

void eliminate(int numOfCan, vector<string> names, vector<vector<int>> votes);

int main()
{
    string line;
    int tests, numOfCan, v;
    cin >> tests;

    for (int test = 0; test < tests; test++)
    {
        cin >> numOfCan;

        vector<string> names(numOfCan);
        vector<vector<int>> votes;

        cin.ignore();

        for (int i = 0; i < numOfCan; i++)
        {
            getline(cin, names[i]);
        }

        while (getline(cin, line) && !line.empty())
        {
            istringstream sinp(line);
            vector<int> tmp(numOfCan);
            for (int i = 0; sinp >> v; i++)
            {
                tmp[i] = v - 1;
            }
            votes.push_back(tmp);
        }

        if (test)
        {
            cout << endl;
        }
           
        eliminate(numOfCan, names, votes);
    }
}

int winner(vector<vector<int>> votes, vector<int> &eliminates, vector<int> &candidates, vector<string> names, int &mn, int &mx)
{
    int all = 0, numOfCan = sz(names);

    for (int i = 0; i < sz(votes); i++)
    { 
        for (int j = 0; j < numOfCan; j++)
        { 
            if (!eliminates[votes[i][j]])
            {
                all++;
                candidates[votes[i][j]]++;
                break;
            }
        }
    }

    for (int i = 0; i < numOfCan; i++)
    {
        if (candidates[i] > all / 2)
        {
            cout << names[i] << endl;
            return 0;
        }
        if (!eliminates[i])
        {
            mn = min(mn, candidates[i]);
            mx = max(mx, candidates[i]);
        }
    }

    if (mn == mx)
    {
        return 1;
    }

    return 2;
}

void eliminate(int numOfCan, vector<string> names, vector<vector<int>> votes)
{
    vector<int> eliminates(numOfCan, 0);
    int left = numOfCan;
    while (left > 1)
    {
        vector<int> candidates(numOfCan);
        int mn = INT_MAX, mx = 0;
        int res = winner(votes, eliminates, candidates, names, mn, mx);

        if (!res)
        {
            return;
        }  
        if (res != 2)
        {
            break;
        }
            
        for (int i = 0; i < numOfCan; i++)
        {
            if (mn == candidates[i])
            {
                eliminates[i] = 1;
                left--;
            }
        }
    }

    for (int i = 0; i < numOfCan; i++)
        if (!eliminates[i])
            cout << names[i] << endl;
}