#include <iostream>
#include "checkers/FullHouseChecker.h"

HandRank FullHouseChecker::check(const Hand& hand) {
    if (hand.isFullHouse()) {
        std::cout << "Detected FULL HOUSE\n";
        return HandRank::FULL_HOUSE;
    }
    if (nextChecker)
        return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
