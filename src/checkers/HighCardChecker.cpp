#include <iostream>
#include "checkers/HighCardChecker.h"

HandRank HighCardChecker::check(const Hand& hand) {
    std::cout << "Detected HIGH CARD\n";
    return HandRank::HIGH_CARD;
}
