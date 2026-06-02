#pragma once
#include <memory>
#include "RewardCommand.h"

enum class CommandTiming {
    Start,
    NextBlind,
    NextAnte
};

struct PendingCommand {
    CommandTiming timing = CommandTiming::Start;
    bool executed = false;
    std::unique_ptr<RewardCommand> command;
};
