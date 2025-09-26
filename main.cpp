#include "src/shuffle.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Helper to print deck (moved here)
void printDeck(const vector<int>& deck) {
    for (int x : deck) cout << x << " ";
    cout << "\n";
}

int main() {
    srand(time(0));

    vector<int> deck;
    int n = 10; // example deck size
    for (int i = 1; i <= n; i++) deck.push_back(i);

    cout << "Original deck:\n";
    printDeck(deck);

    cout << "\nShuffle1:\n";
    shuffle1(deck);
    printDeck(deck);

    // reset
    deck.clear();
    for (int i = 1; i <= n; i++) deck.push_back(i);

    cout << "\nShuffle2:\n";
    shuffle2(deck);
    printDeck(deck);

    // reset
    deck.clear();
    for (int i = 1; i <= n; i++) deck.push_back(i);

    cout << "\nShuffle3:\n";
    shuffle3(deck);
    printDeck(deck);

    return 0;
}
