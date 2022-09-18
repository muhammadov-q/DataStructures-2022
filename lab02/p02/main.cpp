#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    long long cases, number, answer;
    cin >> cases;

    for (int i = 0; i < cases; ++i) 
    {
        cin >> number;

        //number = n*(n+1)/2
        //del = sqrt(b*b - 4*a*c)
        //x1,2 = (-b(+-) del)/2a and here x is always positive
        answer = (sqrt(1 + 8*number) - 1) / 2; 
        cout << answer << "\n";
    }
}