#include <iostream>
#include <memory>
#include "GameManager.h"

void GameManager::runSession() {
    std::cout << "=== Run Started ===\n";

    if (!sessionState.currentBlind) {
        sessionState.currentBlind = std::make_unique<SmallBlindState>();
    }

    Hand hand = handGenerator.generateHand();
    ChosenHand chosenHand = handPlayer.playHand(hand);
    const Hand& scoredHand = chosenHand.toHand();
    int score = scoringRule.scoreHand(scoredHand);

    int targetScore = sessionState.currentBlind->getTargetScore(sessionState.ante);
    bool win = score >= targetScore;

    if (win) {
        int reward = sessionState.currentBlind->getRewardMoney();
        std::cout << "Money gained: " << reward << "\n";
    } else {
        runSessionService.skipBlind(sessionState);
        std::cout << "Blind skipped.\n";
    }

    runSessionService.executePendingCommands(sessionState, CommandTiming::Start);
    std::cout << "=== Run Ended ===\n";
}
