#include <iostream>
#include "checkers/TwoPairChecker.h"

HandRank TwoPairChecker::check(const Hand& hand) {
    if (hand.value == static_cast<int>(HandRank::TWO_PAIR)) {
        std::cout << "Detected TWO PAIR\n";
        return HandRank::TWO_PAIR;
    }
    if (nextChecker)
        return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
