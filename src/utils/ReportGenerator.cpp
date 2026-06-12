#include "utils/ReportGenerator.h"
#include "utils/Logger.h"
#include "world/World.h"
#include "entities/Player.h"

#include <fstream>

ReportGenerator::ReportGenerator() {
}

void ReportGenerator::generateReport(
        World& world,
        Logger& logger,
        const std::string& path) {

    std::ofstream file(path);

    if (!file.is_open()) {
        return;
    }

    Player* player = world.getPlayer();

    file << "REPORTE FINAL DE LA AVENTURA\n";
    file << "============================\n\n";

    if (player != nullptr) {
        file << "Jugador principal: " << player->getName() << '\n';
        file << "Companera: Jimena\n";
        file << "Vida final: " << player->getHealth() << '\n';
        file << "Puntaje final: " << player->getScore() << "\n\n";
    }

    file << "Resultado:\n";

    if (player != nullptr && player->isAlive()) {
        file << "Aventura completada\n\n";
    } else {
        file << "Jugador derrotado\n\n";
    }

    file << "Resumen:\n";
    file << "Chris y Jimena exploraron la mazmorra, recuperaron objetos "
            "valiosos, sobrevivieron a los peligros encontrados y lograron "
            "derrotar a Drogon para completar la aventura\n\n";

    file << "Bitacora de acontecimientos:\n";
    file << "---------------------------\n";

    for (const auto& log : logger.getLogs()) {

        if (log == "El jugador principal es Chris" ||
            log == "Jimena participa como companera de prueba" ||
            log == "El mundo fue cargado desde archivos de texto") {
            continue;
            }

        file << "- " << log << '\n';
    }
}