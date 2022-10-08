#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    for (string line; getline(cin , line);)
    {
        // reverse(line.begin(), line.end());
        // cout << line << endl;
        bool inWord = false;
        string word;
        for (int i = 0; i < sz(line); ++i)
        {
            if (!isspace(line[i]) && !inWord)
            {
                inWord = true;
                word += line[i];
            }
            else if (!isspace(line[i]))
            {
                word += line[i];
            }
            else if (isspace(line[i]) && !word.empty())
            {
                reverse(word.begin(), word.end());
                cout << word << line[i];
                word.clear();
                inWord = false;
            }
            else
            {
                cout << line[i]; //space
            }
        }
        if (!word.empty())
        {
            reverse(word.begin(), word.end());
            cout << word;
        }
        cout << "\n";
    }
}