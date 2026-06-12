#pragma once


#include "items/Inventory.h"
#include "events/TrapEvent.h"
#include "events/RewardEvent.h"
#include "objectives/Objective.h"


class World;
class Logger;

class SimulationEngine {
private:
    World* world;
    Logger* logger;
    bool finished;

    Inventory inventory;
    Objective objective;
    TrapEvent trapEvent;
    RewardEvent rewardEvent;

public:
    SimulationEngine();

    void setWorld(World* world);
    void setLogger(Logger* logger);

    void start();
    void processTurn();
    bool checkEndCondition();
    bool isFinished() const;

};
