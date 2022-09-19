#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    for ( int a,  b;  cin >> a >> b;)
    {
        if (a + b == -2) break;
        int answer = abs(a - b);
 
        if(answer > 50)
            answer = 100 - answer;
 
        cout << answer << "\n";
    }

  
}