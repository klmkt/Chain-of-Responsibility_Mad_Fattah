#include "RewardCommand.h"
#include "RunSessionState.h"

std::string BonusHandCommand::getName() const {
    return "Bonus Hand";
}

std::string BonusHandCommand::getDescription() const {
    return "Gain +1 hand next blind.";
}

void BonusHandCommand::execute(RunSessionState& state) {
    state.remainingPlays += 1;
}

std::string FreePlayingCard::getName() const {
    return "Free Playing Card";
}

std::string FreePlayingCard::getDescription() const {
    return "Gain 1 free playing card added to the deck.";
}

void FreePlayingCard::execute(RunSessionState& state) {
    state.freePlayingCards += 1;
}
