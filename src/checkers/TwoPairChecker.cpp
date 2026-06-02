#include <iostream>
#include "checkers/TwoPairChecker.h"

HandRank TwoPairChecker::check(const Hand& hand) {
    const auto counts = hand.rankCounts();
    int pairCount = 0;
    for (const auto& kv : counts) {
        if (kv.second >= 2) {
            pairCount++;
        }
    }
    if (pairCount >= 2) {
        std::cout << "Detected TWO PAIR\n";
        return HandRank::TWO_PAIR;
    }
    if (nextChecker)
        return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
