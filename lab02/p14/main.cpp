#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;
int main()
{
    iostream::sync_with_stdio(false);
    int Tc, first, next;
    cin >> Tc;
    cout << "Lumberjacks:" << "\n";
    bool increase, decrease;
    for (int i = 0; i < Tc; ++i)
    {
        cin >> first;
        increase = decrease = false;
        for (int j = 0; j < 9; ++j)
        {
            cin >> next;
            if (first < next) increase = true;
            else decrease = true;
            first = next;
        }

        if (increase && decrease)
            cout << "Unordered" << "\n";
        else
            cout << "Ordered" << "\n";
    }
}