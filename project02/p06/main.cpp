#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Team
{
    string mName;
    string mNameLowerCase;
    int nPoints;
    int nGames;
    int nWins;
    int nTies;
    int nLosses;
    int goalScored;
    int goalAgainst;
    int goalDiff;

    Team(string &name)
        : mName(name), mNameLowerCase(name), nPoints(0), nGames(0), nWins(0), nTies(0), nLosses(0),
        goalScored(0), goalAgainst(0), goalDiff(0)
    {
        for (auto &c : mNameLowerCase)
        {
            c = tolower(c);
        }
    }

    void addGameInfo(int goal1, int goal2)
    {
        ++nGames;
        if (goal1 > goal2)
        {
            nPoints += 3;
            ++nWins;
        }
        else if (goal1 == goal2)
        {
            nPoints += 1;
            ++nTies;
        }
        else
        {
            ++nLosses;
        }

        goalScored += goal1;
        goalAgainst += goal2;
        goalDiff += goal1 - goal2;
    }
};
 
ostream &operator<<(ostream &out, const Team &t)
{
    return out << t.mName << " " << t.nPoints << "p, " << t.nGames << "g (" << t.nWins
    << "-" << t.nTies << "-" << t.nLosses << "), " << t.goalDiff 
    << "gd (" << t.goalScored << "-" << t.goalAgainst << ")";
}

struct CmpByNames
{
    bool operator()(const Team &a, const Team &b) const
    {
        return a.mName < b.mName;
    }
};

struct CmpByResult
{
    bool operator()(const Team &a, const Team &b) const
    {
        if (a.nPoints > b.nPoints)
            return true;
        if (a.nPoints < b.nPoints)
            return false;

        if (a.nWins > b.nWins)
            return true;
        if (a.nWins < b.nWins)
            return false;

        if (a.goalDiff > b.goalDiff)
            return true;
        if (a.goalDiff < b.goalDiff)
            return false;

        if (a.goalScored > b.goalScored)
            return true;
        if (a.goalScored < b.goalScored)
            return false;

        if (a.nGames < b.nGames)
            return true;
        if (a.nGames > b.nGames)
            return false;

        return a.mNameLowerCase < b.mNameLowerCase;
    }
};

void parseGameInfo(const string &info, string &team1, int &goal1, int &goal2, string &team2)
{
    size_t indexD1 = info.find("#");
    size_t indexD2 = info.find("@");
    size_t indexD3 = info.rfind("#");

    team1 = info.substr(0, indexD1);
    team2 = info.substr(indexD3 + 1);
    goal1 = stoi(info.substr(indexD1 + 1, indexD2 - indexD1 - 1));
    goal2 = stoi(info.substr(indexD2 + 1, indexD3 - indexD2 - 1));
}

int main()
{
    iostream::sync_with_stdio(false);

    string line;
    getline(cin, line);
    int nTests = stoi(line);
    for (int test = 0; test < nTests; test++)
    {
        string tournament;
        getline(cin, tournament);

        getline(cin, line);
        int nTeams = stoi(line);

        vector<Team> teams;
        for (int i = 0; i < nTeams; i++)
        {
            string name;
            getline(cin, name);
            teams.emplace_back(name);
        }

        getline(cin, line);
        int nGames = stoi(line);

        sort(begin(teams), end(teams), CmpByNames());

        for (int i = 0; i < nGames; i++)
        {
            getline(cin, line);
            string team1;
            int goal1;
            int goal2;
            string team2;
            parseGameInfo(line, team1, goal1, goal2, team2);
            
            auto it1 = lower_bound(begin(teams), end(teams), Team(team1), CmpByNames());
            auto it2 = lower_bound(begin(teams), end(teams), Team(team2), CmpByNames());

            it1->addGameInfo(goal1, goal2);
            it2->addGameInfo(goal2, goal1);
        }

        sort(begin(teams), end(teams), CmpByResult());

        if (test != 0)
        {
            cout << '\n';
        }

        cout << tournament << '\n';
        int rank = 1;
        for (const auto &t : teams)
        {
            cout << rank << ") " << t << "\n";
            rank++;
        }
    }
}