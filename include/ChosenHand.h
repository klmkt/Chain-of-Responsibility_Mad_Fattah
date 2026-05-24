#pragma once

#include "Hand.h"
#include <vector>
#include <algorithm>

class ChosenHand
{
public:
    ChosenHand();
    void setCards(const Hand& hand, const std::vector<int>& indices);
    void selectBestFive(const Hand& hand);
    const Hand& toHand() const;
    const std::vector<Card>& getCards() const;

private:
    Hand chosen;
};
