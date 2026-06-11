#include "engine/AdventureEngine.h"

#include "exceptions/SimulationException.h"

AdventureEngine::AdventureEngine()
    : world(nullptr),
      fileManager(nullptr),
      logger(nullptr),
      reportGenerator(nullptr),
      simulationEngine() {
}

void AdventureEngine::setWorld(World* world) {
    if (world == nullptr) {
        throw SimulationException("El mundo no puede ser nulo");
    }

    this->world = world;
    simulationEngine.setWorld(world);
}

void AdventureEngine::setFileManager(FileManager* fileManager) {
    if (fileManager == nullptr) {
        throw SimulationException("El administrador de archivos no puede ser nulo");
    }

    this->fileManager = fileManager;
}

void AdventureEngine::setLogger(Logger* logger) {
    if (logger == nullptr) {
        throw SimulationException("El logger no puede ser nulo");
    }

    this->logger = logger;
    simulationEngine.setLogger(logger);
}

void AdventureEngine::setReportGenerator(ReportGenerator* reportGenerator) {
    if (reportGenerator == nullptr) {
        throw SimulationException("El generador de reportes no puede ser nulo");
    }

    this->reportGenerator = reportGenerator;
}

void AdventureEngine::loadGameData() {
    if (fileManager == nullptr) {
        throw SimulationException("No se pueden cargar datos sin administrador de archivos");
    }

    if (world == nullptr) {
        throw SimulationException("No se pueden cargar datos sin mundo");
    }
}

void AdventureEngine::runSimulation() {
    if (world == nullptr) {
        throw SimulationException("No se puede ejecutar la simulacion sin mundo");
    }

    simulationEngine.start();

    while (!simulationEngine.isFinished()) {
        simulationEngine.processTurn();
    }
}

void AdventureEngine::generateFinalReport() {
    if (reportGenerator == nullptr) {
        throw SimulationException("No se puede generar el reporte sin generador de reportes");
    }

    if (world == nullptr) {
        throw SimulationException("No se puede generar el reporte sin mundo");
    }

}