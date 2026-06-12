#include <iostream>
#include <exception>
#include <memory>

#include "engine/AdventureEngine.h"

#include "world/World.h"
#include "utils/FileManager.h"
#include "utils/Logger.h"
#include "utils/ReportGenerator.h"

#include "entities/Player.h"
#include "entities/Enemy.h"
#include "items/Inventory.h"

#include "exceptions/GameException.h"
#include "exceptions/SimulationException.h"

int main() {
    try {
        World world;
        FileManager fileManager;
        Logger logger;
        ReportGenerator reportGenerator;

        auto mainPlayer = std::make_unique<Player>("Chris");
        world.setPlayer(std::move(mainPlayer));

        AdventureEngine engine;

        engine.setWorld(&world);
        engine.setFileManager(&fileManager);
        engine.setLogger(&logger);
        engine.setReportGenerator(&reportGenerator);

        engine.loadGameData();
        engine.runSimulation();

        std::cout << "\n===== PRUEBAS DE ERRORES =====\n";

        try {
            Player invalidPlayer("");
        } catch (const std::exception& e) {
            std::cout << "[OK] Error detectado: " << e.what() << '\n';
        }

        try {
            Enemy invalidEnemy("Ghost", "", 50, 10, 20);
        } catch (const std::exception& e) {
            std::cout << "[OK] Error detectado: " << e.what() << '\n';
        }

        try {
            Inventory inventory;
            inventory.addItem(nullptr);
        } catch (const std::exception& e) {
            std::cout << "[OK] Error detectado: " << e.what() << '\n';
        }

        try {
            throw SimulationException("Prueba de excepcion de simulacion");
        } catch (const GameException& e) {
            std::cout << "[OK] GameException detectada: " << e.what() << '\n';
        }

        engine.generateFinalReport();

        std::cout << "\n===== PRUEBAS FINALIZADAS =====\n";

    } catch (const std::exception& e) {
        std::cerr << "Error inesperado: " << e.what() << '\n';
        return 1;
    }

    return 0;
}