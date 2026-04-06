#include <iostream>
#include "checkers/RoyalFlushChecker.h"

HandRank RoyalFlushChecker::check(const Hand& hand) {
    if (hand.value == static_cast<int>(HandRank::ROYAL_FLUSH)) {
        std::cout << "Detected ROYAL FLUSH\n";
        return HandRank::ROYAL_FLUSH;
    }
    if (nextChecker)
        return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
