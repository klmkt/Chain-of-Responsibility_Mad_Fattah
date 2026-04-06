#include <iostream>
#include "checkers/StraightFlushChecker.h"

HandRank StraightFlushChecker::check(const Hand& hand) {
    if (hand.value == static_cast<int>(HandRank::STRAIGHT_FLUSH)) {
        std::cout << "Detected STRAIGHT FLUSH\n";
        return HandRank::STRAIGHT_FLUSH;
    }
    if (nextChecker)
        return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
