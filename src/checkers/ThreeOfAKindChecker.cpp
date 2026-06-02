#include <iostream>
#include "checkers/ThreeOfAKindChecker.h"

HandRank ThreeOfAKindChecker::check(const Hand& hand) {
    const auto counts = hand.rankCounts();
    for (const auto& kv : counts) {
        if (kv.second >= 3) {
            std::cout << "Detected THREE OF A KIND\n";
            return HandRank::THREE_OF_A_KIND;
        }
    }
    if (nextChecker)
        return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
