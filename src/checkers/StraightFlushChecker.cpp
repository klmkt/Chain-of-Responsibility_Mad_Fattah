#include <iostream>
#include "checkers/StraightFlushChecker.h"

HandRank StraightFlushChecker::check(const Hand& hand) {
    if (hand.isStraight() && hand.isFlush()) {
        std::cout << "Detected STRAIGHT FLUSH\n";
        return HandRank::STRAIGHT_FLUSH;
    }
    if (nextChecker)
        return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
