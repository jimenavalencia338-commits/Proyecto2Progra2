#ifndef PROYECTO2_SIMULATION_ENGINE_H
#define PROYECTO2_SIMULATION_ENGINE_H

class World;
class Logger;

class SimulationEngine {
private:
    World* world;
    Logger* logger;
    bool finished;

public:
    SimulationEngine();

    void setWorld(World* world);
    void setLogger(Logger* logger);

    void start();
    void processTurn();
    bool checkEndCondition() const;
    bool isFinished() const;
};

#endif