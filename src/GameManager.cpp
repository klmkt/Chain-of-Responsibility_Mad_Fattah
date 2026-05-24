#include <iostream>
#include "GameManager.h"

void GameManager::runSession() {
    std::cout << "=== Run Started ===\n";
    Hand hand = handGenerator.generateHand();
    ChosenHand chosenHand = handPlayer.playHand(hand);
    Hand scoredHand = chosenHand.toHand();
    int score = scoringRule.scoreHand(scoredHand);
    bool win = blindRule.checkBlind(score);
    int reward = rewardRule.earnMoney(win, score);
    std::cout << "Money gained: " << reward << "\n";
    std::cout << "=== Run Ended ===\n";
}
