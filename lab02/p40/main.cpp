#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

bool vowel[128];
int main()
{
    iostream::sync_with_stdio(false);
    vowel['A'] = vowel['a'] 
    = vowel['E'] = vowel['e']
    = vowel['I'] = vowel['i'] 
    = vowel['O'] = vowel['o'] 
    = vowel['U'] = vowel['u'] = true;
    
    string line, word, sep;
    while (getline(cin, line))
    {
        for (int i = 0; i < sz(line); ++i)
        {
            if (isalpha(line[i]))
            {
                char startingCharacter = line[i];
                if (vowel[startingCharacter])
                {
                    cout << startingCharacter;
                }
                i++;

                for (; i < sz(line) && isalpha(line[i]); i++)
                {
                    cout << line[i];
                }
                    
                if (!vowel[startingCharacter])
                {
                     cout << startingCharacter;
                }
            
                cout << "ay";
                i--;
            }
            else
            {
                cout << line[i];
            }
                
        }
        cout << '\n';
    }
}