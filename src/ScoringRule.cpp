#include <iostream>
#include "ScoringRule.h"

ScoringRule::ScoringRule() {
    // Build the chain from highest to lowest rank
    royalFlushChecker.setNext(&straightFlushChecker);
    straightFlushChecker.setNext(&fiveOfAKindChecker);
    fiveOfAKindChecker.setNext(&fourOfAKindChecker);
    fourOfAKindChecker.setNext(&flushHouseChecker);
    flushHouseChecker.setNext(&fullHouseChecker);
    fullHouseChecker.setNext(&flushFiveChecker);
    flushFiveChecker.setNext(&flushChecker);
    flushChecker.setNext(&straightChecker);
    straightChecker.setNext(&threeOfAKindChecker);
    threeOfAKindChecker.setNext(&twoPairChecker);
    twoPairChecker.setNext(&pairChecker);
    pairChecker.setNext(&highCardChecker);
}

int ScoringRule::scoreHand(const Hand& hand) {
    std::cout << "Calculating hand score...\n";
    HandRank rank = royalFlushChecker.check(hand);
    int score = convertRankToScore(rank);
    std::cout << "Final score = " << score << "\n";
    return score;
}

int ScoringRule::convertRankToScore(HandRank rank) {
    switch (rank) {
    case HandRank::ROYAL_FLUSH:
        return 100;
    case HandRank::STRAIGHT_FLUSH:
        return 90;
    case HandRank::FIVE_OF_A_KIND:
        return 85;
    case HandRank::FOUR_OF_A_KIND:
        return 50;
    case HandRank::FLUSH_HOUSE:
        return 40;
    case HandRank::FULL_HOUSE:
        return 35;
    case HandRank::FLUSH_FIVE:
        return 32;
    case HandRank::FLUSH:
        return 30;
    case HandRank::STRAIGHT:
        return 25;
    case HandRank::THREE_OF_A_KIND:
        return 20;
    case HandRank::TWO_PAIR:
        return 15;
    case HandRank::PAIR:
        return 10;
    case HandRank::HIGH_CARD:
    default:
        return 5;
    }
}