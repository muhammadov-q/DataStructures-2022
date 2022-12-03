#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

vector<string> split(const string &line)
{
    istringstream sinp(line);
    vector<string> res;
    for (string w; sinp >> w;)
    {
        res.push_back(w);
    }

    return res;
}

int main()
{
    iostream::sync_with_stdio(false);
    string line;
    getline(cin, line);

    auto attributes = split(line);

    getline(cin, line);
    int nSongs = stoi(line);

    vector<vector<string>> songs;
    for (int i = 0; i < nSongs; i++)
    {
        getline(cin, line);
        songs.push_back(split(line));
    }

    getline(cin, line);
    int nCmd = stoi(line);

    for (int i = 0; i < nCmd; i++)
    {
        string attribute;
        getline(cin, attribute);
        int nAttribute = find(begin(attributes), end(attributes), attribute) - begin(attributes);

        stable_sort(begin(songs), end(songs),
                    [&nAttribute](const auto &a, const auto &b) 
                    { return a[nAttribute] < b[nAttribute]; });

        if (i != 0)
        {
            cout << "\n";
        }

        for (const auto &attr : attributes)
        {
            cout << attr << " ";
        }
        cout << "\n";
        
        for (const auto &song : songs)
        {
            for (const auto &attr : song)
            {
                cout << attr << " ";
            }
            cout << "\n";
        }
    }
}