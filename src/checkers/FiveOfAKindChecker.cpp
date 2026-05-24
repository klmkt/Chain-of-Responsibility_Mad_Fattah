#include <iostream>
#include "checkers/FiveOfAKindChecker.h"

HandRank FiveOfAKindChecker::check(const Hand& hand) {
    const auto counts = hand.rankCounts();
    for (const auto& kv : counts) {
        if (kv.second >= 5) {
            std::cout << "Detected FIVE OF A KIND\n";
            return HandRank::FIVE_OF_A_KIND;
        }
    }
    if (nextChecker)
        return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
