#include <iostream>
#include "checkers/ThreeOfAKindChecker.h"

HandRank ThreeOfAKindChecker::check(const Hand& hand) {
    if (hand.value == static_cast<int>(HandRank::THREE_OF_A_KIND)) {
        std::cout << "Detected THREE OF A KIND\n";
        return HandRank::THREE_OF_A_KIND;
    }
    if (nextChecker)
        return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}
