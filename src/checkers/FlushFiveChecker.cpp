#include <iostream>
#include "checkers/FlushFiveChecker.h"

HandRank FlushFiveChecker::check(const Hand& hand) {
    if (hand.value == static_cast<int>(HandRank::FLUSH_FIVE)) {
        std::cout << "Detected FLUSH FIVE\n";
        return HandRank::FLUSH_FIVE;
    }
    if (nextChecker)
        return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
