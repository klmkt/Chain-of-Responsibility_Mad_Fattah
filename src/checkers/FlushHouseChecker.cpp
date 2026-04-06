#include <iostream>
#include "checkers/FlushHouseChecker.h"

HandRank FlushHouseChecker::check(const Hand& hand) {
    if (hand.value == static_cast<int>(HandRank::FLUSH_HOUSE)) {
        std::cout << "Detected FLUSH HOUSE\n";
        return HandRank::FLUSH_HOUSE;
    }
    if (nextChecker)
        return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
