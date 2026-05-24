#include <iostream>
#include "checkers/StraightChecker.h"

HandRank StraightChecker::check(const Hand& hand) {
    if (hand.isStraight()) {
        std::cout << "Detected STRAIGHT\n";
        return HandRank::STRAIGHT;
    }
    if (nextChecker)
        return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
