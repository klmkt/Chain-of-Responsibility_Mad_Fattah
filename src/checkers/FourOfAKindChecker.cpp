#include <iostream>
#include "checkers/FourOfAKindChecker.h"

HandRank FourOfAKindChecker::check(const Hand& hand) {
    const auto counts = hand.rankCounts();
    for (const auto& kv : counts) {
        if (kv.second >= 4) {
            std::cout << "Detected FOUR OF A KIND\n";
            return HandRank::FOUR_OF_A_KIND;
        }
    }
    if (nextChecker)
        return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
