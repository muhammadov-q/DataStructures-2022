#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

        int numOfFriends; 
        cin >> numOfFriends;

        //string names[numOfFriends];
        vector<string> names(numOfFriends);
        //int money[numOfFriends];
        vector<int> money(numOfFriends);

        for (int i = 0; i < numOfFriends; i++)
        {
            money[i] = 0;
        }

        for (int i = 0; i < numOfFriends; i++)
        {
            cin >> names[i];
        }

        for (int i = 0; i < numOfFriends; i++)
        {
            string giver; 
            cin >> giver;
            int moneygiven;
            cin >> moneygiven;
            int numOfPeople;
            cin >> numOfPeople;

            if (moneygiven == 0 && numOfPeople == 0) continue;
            
            int moneyPerPerson = moneygiven / numOfPeople;
            int remainder = moneygiven % numOfPeople;

            for (int j = 0; j < numOfPeople; j++)
            {
                string reciever;
                cin >> reciever;
                for (int h = 0; h < numOfFriends; h++)
                {
                    if (reciever == names[h])
                    {
                        money[h] += moneyPerPerson;
                    }
                }
            }

            for (int k = 0; k < numOfFriends; k++)
            {
                if (giver == names[k])
                {
                    money[k] -= moneygiven;
                    money[k] += remainder;
                }
            }
        }

        for (int i = 0; i < numOfFriends; i++)
        {
            cout << names[i] << " " << money[i] << "\n";
        }
    
}