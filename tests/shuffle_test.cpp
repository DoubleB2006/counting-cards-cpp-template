#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/shuffle.hpp"
#include <vector>
#include <algorithm> // std::is_permutation

using namespace std;

TEST_CASE("Shuffle algorithms produce valid permutations") {
    vector<int> original = {1,2,3,4,5};

    SECTION("Shuffle1") {
        vector<int> deck = original;
        shuffle1(deck);
        REQUIRE(deck.size() == original.size());
        REQUIRE(std::is_permutation(deck.begin(), deck.end(),
                                    original.begin()));
    }

    SECTION("Shuffle2") {
        vector<int> deck = original;
        shuffle2(deck);
        REQUIRE(deck.size() == original.size());
        REQUIRE(std::is_permutation(deck.begin(), deck.end(),
                                    original.begin()));
    }

    SECTION("Shuffle3") {
        vector<int> deck = original;
        shuffle3(deck);
        REQUIRE(deck.size() == original.size());
        REQUIRE(std::is_permutation(deck.begin(), deck.end(),
                                    original.begin()));
    }
}

TEST_CASE("Benchmarking shuffle algorithms with large decks") {
    const int n = 10000;
    vector<int> deck(n);
    iota(deck.begin(), deck.end(), 1);

    BENCHMARK("Shuffle1 10k") {
        vector<int> d = deck;
        shuffle1(d);
        return d[0]; // return something to prevent optimization
    };

    BENCHMARK("Shuffle2 10k") {
        vector<int> d = deck;
        shuffle2(d);
        return d[0];
    };

    BENCHMARK("Shuffle3 10k") {
        vector<int> d = deck;
        shuffle3(d);
        return d[0];
    };
}
