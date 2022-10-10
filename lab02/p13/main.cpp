#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    for (int banks, debentures; cin >> banks >> debentures;)
    {
        if (banks + debentures == 0) break;
        
        vector <int> cashReserve(debentures);
        for (int i = 0 ; i < banks ; ++i) {
            cin >> cashReserve[i];
        }
    
        for (int i = 0 ; i < debentures ; ++i)
        {
            int debtor, creditor, money;
            cin >> debtor >> creditor >> money;
            cashReserve[creditor - 1] += money;
            cashReserve[debtor - 1] -= money;
        }
        
        bool isPositive = true;
        for(int i = 0 ; i < banks ; ++i)
        {
            if(cashReserve[i] < 0)
            {
                isPositive = false;
                break;
            }
        }

        cout << (isPositive ? "S" : "N") << "\n";
    }
}