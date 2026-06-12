#pragma once

#include "engine/SimulationEngine.h"

class World;
class FileManager;
class Logger;
class ReportGenerator;

class AdventureEngine {
private:
    World* world;
    FileManager* fileManager;
    Logger* logger;
    ReportGenerator* reportGenerator;
    SimulationEngine simulationEngine;

public:
    AdventureEngine();

    void setWorld(World* world);
    void setFileManager(FileManager* fileManager);
    void setLogger(Logger* logger);
    void setReportGenerator(ReportGenerator* reportGenerator);

    void loadGameData();
    void runSimulation();
    void generateFinalReport();

};

