#pragma once

#include "GameEvent.h"

class Player;
class Logger;

class RewardEvent : public GameEvent {
private:
    int rewardPoints;

public:
    RewardEvent(const std::string& description, int rewardPoints);

    void trigger(Player& player, Logger& logger) override;

    int getRewardPoints() const;
};