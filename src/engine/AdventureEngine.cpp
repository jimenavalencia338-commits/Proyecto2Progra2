#include "engine/AdventureEngine.h"

#include "world/World.h"
#include "utils/FileManager.h"
#include "utils/Logger.h"
#include "utils/ReportGenerator.h"
#include "exceptions/SimulationException.h"

#include <filesystem>
#include <iostream>


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

    const std::filesystem::path projectRoot =
            std::filesystem::current_path().parent_path();

    const std::filesystem::path dataPath = projectRoot / "data";

    fileManager->createBaseFiles(dataPath);
    fileManager->loadWorld(*world, dataPath);
}

void AdventureEngine::runSimulation() {
    if (world == nullptr) {
        throw SimulationException("No se puede ejecutar la simulacion sin mundo");
    }

    if (logger == nullptr) {
        throw SimulationException("No se puede ejecutar la simulacion sin logger");
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

    if (world == nullptr) {
        throw SimulationException("No se puede generar el reporte sin mundo");
    }

    const std::filesystem::path projectRoot =
            std::filesystem::current_path().parent_path();

    const std::filesystem::path outputPath = projectRoot / "output";

    std::filesystem::create_directories(outputPath);

    logger->exportLog((outputPath / "log.txt").string());

    reportGenerator->generateReport(
            *world,
            *logger,
            (outputPath / "final_report.txt").string()
    );

    std::cout << "\n===== ARCHIVOS GENERADOS =====\n";
    std::cout << "Datos: " << (projectRoot / "data").string() << '\n';
    std::cout << "Bitacora: " << (outputPath / "log.txt").string() << '\n';
    std::cout << "Reporte final: " << (outputPath / "final_report.txt").string() << '\n';
}