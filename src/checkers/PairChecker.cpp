#include <iostream>
#include "checkers/PairChecker.h"

HandRank PairChecker::check(const Hand& hand) {
    const auto counts = hand.rankCounts();
    for (const auto& kv : counts) {
        if (kv.second >= 2) {
            std::cout << "Detected PAIR\n";
            return HandRank::PAIR;
        }
    }
    if (nextChecker)
        return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
