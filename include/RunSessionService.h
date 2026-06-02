#pragma once
#include "BlindState.h"
#include "RunSessionState.h"

class RunSessionService {
public:
    void skipBlind(RunSessionState& state);
    void executePendingCommands(RunSessionState& state, CommandTiming timing);

private:
    void resetBlindResources(RunSessionState& state);
};
