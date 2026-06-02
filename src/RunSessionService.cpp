#include "RunSessionService.h"

void RunSessionService::skipBlind(RunSessionState& state) {
    if (!state.currentBlind) {
        return;
    }

    PendingCommand command = state.currentBlind->createSkipRewardCommand();
    state.pendingCommands.push_back(std::move(command));
    state.currentBlind = state.currentBlind->nextState(state.ante);
    resetBlindResources(state);
}

void RunSessionService::executePendingCommands(RunSessionState& state, CommandTiming timing) {
    for (auto& pending : state.pendingCommands) {
        if (!pending.executed && pending.timing == timing && pending.command) {
            pending.command->execute(state);
            pending.executed = true;
        }
    }
}

void RunSessionService::resetBlindResources(RunSessionState& state) {
    (void)state;
}
