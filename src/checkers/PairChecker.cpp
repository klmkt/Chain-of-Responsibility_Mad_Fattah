#include <iostream>
#include "checkers/PairChecker.h"

HandRank PairChecker::check(const Hand& hand) {
    if (hand.value == static_cast<int>(HandRank::PAIR)) {
        std::cout << "Detected PAIR\n";
        return HandRank::PAIR;
    }
    if (nextChecker)
        return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
