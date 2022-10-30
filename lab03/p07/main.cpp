#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

class Game
{
    friend ostream &operator<<(ostream &out, const Game &game);
    vector<string> board;

public: 
    Game(const string &descr)
        : board(8, string(8, '.'))
    {
        int r = 0;
        int c = 0;
        for (auto e : descr)
        {
            if (e == '/')
            {
                ++r;
                c = 0;
            }
            else if (isdigit(e))
            {
                c += e - '0';
            }
            else
            {
                board[r][c] = e;
                ++c;
            }

        }
    }

    int solve()
    {
        for (int r = 0; r < 8; ++r)
        {
            for (int c = 0; c < 8; ++c)
            {
                switch(board[r][c])
                {
                    case 'p':
                        attackByBlackPawn(r, c);
                        break;
                    case 'P':
                        attackByWhitePawn(r, c);
                        break;
                    case 'r':
                    case 'R':
                        attackByRook(r, c);
                        break;
                    case 'b':
                    case 'B':
                        attackByBishop(r, c);
                        break;
                    case 'q':
                    case 'Q':
                        attackByQueen(r, c);
                        break;
                    case 'k':
                    case 'K':
                        attackByKing(r, c);
                        break;
                    case 'n':
                    case 'N':
                        attackByKnight(r, c);
                        break;
                }    
            }
        }
        int res = 0;
        for (auto const &row : board)
        {
            res += count(row.begin(), row.end(), '.');
        }

        return res;
    }

    void attackByBlackPawn(int r, int c)
    {
        if (check(r+1, c-1) && (board[r+1][c-1] == '.' ||board[r+1][c-1] == '*'))
        {
            board[r+1][c-1] = '*';
        }
        if (check(r+1, c+1) && (board[r+1][c+1] == '.' ||board[r+1][c+1] == '*'))
        {
            board[r+1][c+1] = '*';
        }
    }

    void attackByWhitePawn(int r, int c)
    {
        if (check(r-1, c-1) && (board[r-1][c-1] == '.' ||board[r-1][c-1] == '*'))
        {
            board[r-1][c-1] = '*';
        }
        if (check(r-1, c+1) && (board[r-1][c+1] == '.' ||board[r-1][c+1] == '*'))
        {
            board[r-1][c+1] = '*';
        }
    }

    void attackByRook(int r, int c)
    {
        attackInDir(r ,c ,0 , 1);
        attackInDir(r ,c ,0 , -1);
        attackInDir(r ,c ,-1 , 0);
        attackInDir(r ,c ,1 , 0);
    }

    void attackByBishop(int r, int c)
    {
        attackInDir(r ,c ,1 , 1);
        attackInDir(r ,c ,1 , -1);
        attackInDir(r ,c ,-1 , -1);
        attackInDir(r ,c ,-1 , 1);
    }

    void attackByQueen(int r, int c)
    {
        attackByRook(r, c);
        attackByBishop(r, c);
    }

    void attackInDir(int r, int c, int dr, int dc)
    {
        while(check(r+dr, c+dc) && (board[r+dr][c+dc] == '.' || board[r+dr][c+dc] == '*'))
        {
            r += dr;
            c += dc;
            board[r][c] = '*';
        }
    }

    void attackByKing(int r, int c)
    {
        for (int tr = r-1; tr <= r+1; ++tr)
        {
            for (int tc = c-1; tc <= c+1; ++tc)
            {
                if (check(tr, tc) && board[tr][tc] == '.')
                {
                    board[tr][tc] = '*';
                }
            }
        }
    }

    void attackByKnight(int r, int c)
    {
        static const vector<int> dr = {-2, -1, 1, 2, 2, 1, -1, -2};
        static const vector<int> dc = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int i = 0; i < sz(dr); ++i)
        {
            int tr = r + dr[i];
            int tc = c + dc[i];
            if (check(tr, tc) && board[tr][tc] == '.')
            {
                    board[tr][tc] = '*';
            }
        }
    }

    bool check(int r, int c)
    {
        return 0 <= r && r < 8 && 0 <= c && c < 8;
    }

};

ostream &operator<<(ostream &out, const Game &game)
{
    for (const auto &row : game.board)
    {
        out << row << endl;
    }

    return out;
}

int main()
{
    iostream::sync_with_stdio(false);
    for (string gameDescription; getline(cin, gameDescription);)
    {
        Game game(gameDescription);
        cout << game.solve() << "\n";

        // cout << game << endl;
        // cout << "----" << endl;
    }
}