#include "../../include/events/RewardEvent.h"

RewardEvent::RewardEvent(
        const std::string& description,
        int rewardPoints)
        : GameEvent(description),
          rewardPoints(rewardPoints) {
}

void RewardEvent::trigger(Player& player, Logger& logger) {
    activated = true;

    // Se implementará cuando Player y Logger estén listos
}

int RewardEvent::getRewardPoints() const {
    return rewardPoints;
}