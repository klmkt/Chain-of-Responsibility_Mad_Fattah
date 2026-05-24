#include <iostream>
#include "HandPlayer.h"
ChosenHand HandPlayer::playHand(const Hand& hand)
{
    std::cout << "Player selects cards to play...\n";
    ChosenHand chosen;
    chosen.selectBestFive(hand);
    const auto& cards = chosen.getCards();
    std::cout << "Selected cards:\n";
    for (const auto& card : cards) {
        std::cout << "  [" << card.rank << card.suit << "]\n";
    }
    return chosen;
}