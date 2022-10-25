#pragma once
#include <iostream>

vector<int> createDeck()
{
    vector<int> result(52);

    for (int i = 0; i < 52; ++i)
        result[i] = i;

    return result;
}

void applyShuffleToDeck(vector<int> &deck, const vector<int> &shuffle)
{
    vector<int> temp(52);

    for (int i = 0; i < 52; ++i)
        temp[i] = deck[shuffle[i] - 1];

    deck = temp;
}

void printDeck(const vector<int> &deck)
{
    static vector<string> ranks = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    static vector<string> suits = {"Clubs", "Diamonds", "Hearts", "Spades"};

    for (auto card : deck)
        cout << ranks[card % 13] << " of " << suits[card / 13] << endl;
}

vector<vector<int>> readShuffles()
{
    int nShuffles;
    cin >> nShuffles;

    vector<vector<int>> result(nShuffles, vector<int>(52));

    for (int i = 0; i < nShuffles; ++i)
        for (int j = 0; j < 52; ++j)
            cin >> result[i][j];

    cin.ignore(1024, '\n');

    return result;
}