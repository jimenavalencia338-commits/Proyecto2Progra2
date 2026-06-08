#pragma once

#include "GameEvent.h"

class Player;
class Logger;

class TrapEvent : public GameEvent {
private:
    int damage;

public:
    TrapEvent(const string& description, int damage);

    void trigger(Player& player, Logger& logger) override;

    int getDamage() const;
};