#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    bool newLine = false;
    int n; 
    while (cin >> n && n)
    {
        vector<string> vc(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vc[i];
        }

        stable_sort(vc.begin(), vc.end(), [](string a, string b)
                    {
                        a = a.substr(0, 2);
                        b = b.substr(0, 2);
                        return a < b;
                    });
        if (newLine)
        {
            cout << "\n";
        }
        
        for (int i = 0; i < n; i++)
        {
            cout << vc[i] << endl;
        }

        newLine = true;
    }
}