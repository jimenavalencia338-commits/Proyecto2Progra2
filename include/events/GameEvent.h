#pragma once

#include <string>

using namespace std;

class Player;
class Logger;

class GameEvent {
protected:
    string description;
    bool activated;

public:
    GameEvent(const string& description);

    virtual ~GameEvent() = default;

    virtual void trigger(Player& player, Logger& logger) = 0;

    bool isActivated() const;
};

