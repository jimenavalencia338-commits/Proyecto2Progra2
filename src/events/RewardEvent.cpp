#include "events/RewardEvent.h"
#include "entities/Player.h"
#include "utils/Logger.h"

RewardEvent::RewardEvent(
        const std::string& description,
        int rewardPoints)
        : GameEvent(description),
          rewardPoints(rewardPoints) {
}

void RewardEvent::trigger(Player& player, Logger& logger) {
    if (activated) {
        return;
    }

    player.addScore(rewardPoints);
    logger.writeLog(description);

    activated = true;
}

int RewardEvent::getRewardPoints() const {
    return rewardPoints;
}