#include <iostream>
#include "checkers/FiveOfAKindChecker.h"

HandRank FiveOfAKindChecker::check(const Hand& hand) {
    if (hand.value == static_cast<int>(HandRank::FIVE_OF_A_KIND)) {
        std::cout << "Detected FIVE OF A KIND\n";
        return HandRank::FIVE_OF_A_KIND;
    }
    if (nextChecker)
        return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
