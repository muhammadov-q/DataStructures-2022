#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    string a, b;
    while(cin >> a >> b)
    {
        map<char, int> A;
        map<char, int> B;
        map<char, int>::iterator itr;

        for (int i = 0; i < sz(b); i++)
        {
            A[a[i]]++;
        }
        for (int i = 0; i < sz(b); i++)
        {
            B[b[i]]++;
        }

        vector<int> x, y;
        itr = A.begin();
        while(itr != A.end())
        {
            x.push_back(itr->second);
            itr++;
        }

        itr = B.begin();
        while(itr != B.end())
        {
            y.push_back(itr->second);
            itr++;
        }

        bool isTrue = true;
        for (int i = 0; i < sz(x); i++)
        {
            if (x[i] != y[i])
            {
                isTrue = false;
                break;
            }
        }
        cout << (isTrue ? "YES" : "NO") << "\n";
    }
}