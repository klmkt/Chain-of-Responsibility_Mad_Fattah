#include "ChosenHand.h"
#include <iostream>

ChosenHand::ChosenHand()
{
}

void ChosenHand::setCards(const Hand& hand, const std::vector<int>& indices)
{
    chosen.cards.clear();
    for (int index : indices) {
        if (index >= 0 && index < static_cast<int>(hand.cards.size())) {
            chosen.cards.push_back(hand.cards[index]);
        }
    }
}

void ChosenHand::selectBestFive(const Hand& hand)
{
    chosen.cards.clear();
    if (hand.cards.size() <= 5) {
        chosen.cards = hand.cards;
        return;
    }

    std::vector<Card> sorted = hand.cards;
    std::sort(sorted.begin(), sorted.end(), [](const Card& a, const Card& b) {
        if (a.rank != b.rank) return a.rank > b.rank;
        return a.suit < b.suit;
    });

    chosen.cards.assign(sorted.begin(), sorted.begin() + 5);
}

const Hand& ChosenHand::toHand() const
{
    return chosen;
}

const std::vector<Card>& ChosenHand::getCards() const
{
    return chosen.cards;
}
