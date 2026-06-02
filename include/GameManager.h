#pragma once
#include "Hand.h"
#include "HandGenerator.h"
#include "HandPlayer.h"
#include "ScoringRule.h"
#include "RunSessionService.h"

class GameManager
{
public:
    void runSession();

private:
    HandGenerator handGenerator;
    HandPlayer handPlayer;
    ScoringRule scoringRule;
    RunSessionService runSessionService;
    RunSessionState sessionState;
};