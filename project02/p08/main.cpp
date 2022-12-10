#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

void action01(vector<int> &v)
{
    for (int i = 0; i < sz(v); i++)
    {
        for (int j = 0; j < sz(v); j++)
        {
            if (v[i] != v[j] && (v[i] + v[j] == 7777))
            {
                cout << "yes" << "\n";
                exit(1); 
            }
        }
    }
    cout << "no";

}

void action02(vector<int> &v)
{
    int sum = 0;
    for (int x : v)
    {
        auto it = lower_bound(v.begin(), v.end(), x);
        auto it2 = upper_bound(v.begin(), v.end(), x);

        sum += it2 - it;
    }

    cout << (sum == sz(v) ? "Unique\n" : "Contains duplicate\n");
}

void action03(vector<int> &v, int &n)
{
    bool a = true;
    for (int x : v)
    {
        auto it = lower_bound(v.begin(), v.end(), x);
        auto it2 = upper_bound(v.begin(), v.end(), x);

        if (it2 - it > n / 2)
        {
            cout << *it;
            a = false;
            break;
        }
    }

    if (a)
    {
        cout << -1;
    }
        
}

void action04(vector<int> &v, int &n)
{
    if (n % 2 == 1)
    {
        cout << v[n / 2];
    } 
    else
    {
        cout << v[n / 2 - 1] << " " << v[n / 2];
    } 
}

void action05(vector<int> &v)
{
    for (int i = 0; i < sz(v); i++)
    {
        if (v[i] >= 100 && v[i] <= 999)
        {
            cout << v[i] << " ";
        }
    }
}

int main()
{
    iostream::sync_with_stdio(false);
    int n, t;
    cin >> n >> t;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), [](int a, int b)
        {
            return a < b;
        });
    
    switch (t)
    {
        case 1: action01(v); break;
        case 2: action02(v); break;
        case 3: action03(v, n); break;
        case 4: action04(v, n); break;
        case 5: action05(v); break;
    }
    cout << "\n";
}