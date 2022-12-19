#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

enum class Event
{
    Departure,
    Arrival
};

int convertToMinutes(const string &date, const string &time)
{
    static vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31};

    int res = 60 * stoi(time.substr(0, 2)) + stoi(time.substr(3));

    int y = stoi(date.substr(0, 4));
    int m = stoi(date.substr(5, 2));
    int d = stoi(date.substr(8));

    res += 365 * 24 * 60 * (y - 2013);

    for (int i = 1; i < m; ++i)
    {
        res += 24 * 60 * days[i - 1];
        if (i == 2 && y == 2016)
        {
            res += 24 * 60;
        }
    }

    res += 24 * 60 * (d - 1);

    return res;
}

int main()
{
    iostream::sync_with_stdio(false);

    int nTests;
    cin >> nTests;

    for (int test = 0; test < nTests; test++)
    {
        int nClients;
        cin >> nClients;

        int cleaningTime;
        cin >> cleaningTime;

        vector<pair<int, Event>> events;
        for (int i = 0; i < nClients; i++)
        {
            string code, dateA, timeA, dateD, timeD;
            cin >> code >> dateA >> timeA >> dateD >> timeD;
            events.emplace_back(convertToMinutes(dateA, timeA), Event::Arrival);
            events.emplace_back(convertToMinutes(dateD, timeD) + cleaningTime, Event::Departure);
        }

        sort(begin(events), end(events));

        int res = 0;
        int curNumOfClients = 0;
        for (const auto &event : events)
        {
            if (event.second == Event::Departure)
            {
                --curNumOfClients;
            }
            else
            {
                res = max(++curNumOfClients, res);
            }
        } 

        cout << res << "\n";
    }
}