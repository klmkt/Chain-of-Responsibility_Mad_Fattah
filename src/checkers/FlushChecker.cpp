#include <iostream>
#include "checkers/FlushChecker.h"

HandRank FlushChecker::check(const Hand& hand) {
    if (hand.value == static_cast<int>(HandRank::FLUSH)) {
        std::cout << "Detected FLUSH\n";
        return HandRank::FLUSH;
    }
    if (nextChecker)
        return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
