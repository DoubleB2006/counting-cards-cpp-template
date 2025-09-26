#include "shuffle.hpp"
#include <iostream>
#include <cstdlib> // rand, srand
#include <ctime>   // time

using namespace std;

// Shuffle Algorithm 1: naive
void shuffle1(vector<int>& deck) {
    int n = deck.size();
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        swap(deck[i], deck[j]);
    }
}

// Shuffle Algorithm 2: biased
void shuffle2(vector<int>& deck) {
    int n = deck.size();
    for (int i = 0; i < n; i++) {
        int j = i + rand() % (n - i);
        swap(deck[i], deck[j]);
    }
}

// Shuffle Algorithm 3: Fisher–Yates
void shuffle3(vector<int>& deck) {
    int n = deck.size();
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(deck[i], deck[j]);
    }
}


