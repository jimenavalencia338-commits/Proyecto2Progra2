#include "engine/SimulationEngine.h"

#include "world/World.h"
#include "world/Room.h"
#include "entities/Player.h"
#include "entities/Enemy.h"
#include "utils/Logger.h"
#include "exceptions/SimulationException.h"

#include <iostream>
#include <memory>

SimulationEngine::SimulationEngine()
    : world(nullptr),
      logger(nullptr),
      finished(false),
      objective("Derrotar a Drogon y completar la aventura"),
      trapEvent("Chris activo una trampa y recibio dano", 40),
      rewardEvent("Chris recibio una recompensa adicional por avanzar en la aventura", 0) {
}

void SimulationEngine::setWorld(World* world) {
    if (world == nullptr) {
        throw SimulationException("El mundo de la simulacion no puede ser nulo");
    }

    this->world = world;
}

void SimulationEngine::setLogger(Logger* logger) {
    if (logger == nullptr) {
        throw SimulationException("El logger de la simulacion no puede ser nulo");
    }

    this->logger = logger;
}

void SimulationEngine::start() {
    if (world == nullptr) {
        throw SimulationException("No se puede iniciar la simulacion sin un mundo");
    }

    if (logger == nullptr) {
        throw SimulationException("No se puede iniciar la simulacion sin logger");
    }

    Player* player = world->getPlayer();

    if (player == nullptr) {
        throw SimulationException("No se puede iniciar la simulacion sin jugador");
    }

    Room* entrance = world->getRoomById(1);

    if (entrance == nullptr) {
        throw SimulationException("No se encontro la habitacion inicial");
    }

    player->setCurrentRoom(entrance);
    finished = false;

    logger->writeLog("La aventura inicio");
    logger->writeLog("El jugador principal es Chris");
    logger->writeLog("Jimena participa como companera de prueba");
    logger->writeLog("El mundo fue cargado desde archivos de texto");
}

void SimulationEngine::processTurn() {
    if (finished) {
        return;
    }

    Player* player = world->getPlayer();

    if (player == nullptr) {
        throw SimulationException("No existe jugador en el mundo");
    }

    Player partner("Jimena");

    Room* entrance = world->getRoomById(1);
    Room* hallway = world->getRoomById(2);
    Room* treasureRoom = world->getRoomById(3);
    Room* dragonLair = world->getRoomById(4);

    if (entrance == nullptr || hallway == nullptr ||
        treasureRoom == nullptr || dragonLair == nullptr) {
        throw SimulationException("No se pudo cargar correctamente el mapa");
    }

    std::cout << "===== SIMULACION DE AVENTURA =====\n\n";

    std::cout << "Jugador: " << player->getName()
              << " | Vida: " << player->getHealth()
              << " | Ataque: " << player->getAttackPower() << '\n';

    std::cout << "Companera: " << partner.getName()
              << " | Vida: " << partner.getHealth()
              << " | Ataque: " << partner.getAttackPower() << "\n\n";

    std::cout << "===== RECORRIDO POR HABITACIONES =====\n";

    Room* currentRoom = player->getCurrentRoom();

    std::cout << player->getName() << " entra a " << currentRoom->getName() << '\n';
    logger->writeLog("Chris entro a " + currentRoom->getName());

    auto& entranceItems = currentRoom->getItems();
    while (!entranceItems.empty()) {
        std::cout << player->getName()
                  << " encuentra "
                  << entranceItems[0]->getName() << '\n';

        logger->writeLog("Chris encontro " + entranceItems[0]->getName());

        inventory.addItem(std::move(entranceItems[0]));
        entranceItems.erase(entranceItems.begin());
    }

    player->moveTo(hallway);
    currentRoom = player->getCurrentRoom();

    std::cout << player->getName()
              << " se mueve a "
              << currentRoom->getName() << '\n';

    logger->writeLog("Chris se movio a " + currentRoom->getName());

    player->moveTo(treasureRoom);
    currentRoom = player->getCurrentRoom();

    std::cout << player->getName()
              << " se mueve a "
              << currentRoom->getName() << '\n';

    logger->writeLog("Chris se movio a " + currentRoom->getName());

    auto& treasureItems = currentRoom->getItems();
    while (!treasureItems.empty()) {
        std::cout << player->getName()
                  << " encuentra "
                  << treasureItems[0]->getName() << '\n';

        logger->writeLog("Chris encontro " + treasureItems[0]->getName());

        inventory.addItem(std::move(treasureItems[0]));
        treasureItems.erase(treasureItems.begin());
    }

    std::cout << "\n===== INVENTARIO =====\n";
    inventory.listItems();

    std::cout << "\n===== USO DE OBJETOS Y EVENTOS =====\n";

    trapEvent.trigger(*player, *logger);

    std::cout << player->getName()
              << " activa una trampa, vida actual: "
              << player->getHealth() << '\n';

    Item* potion = inventory.findItem("Small Potion");
    if (potion != nullptr) {
        potion->use(*player);
        logger->writeLog("Chris uso Small Potion y recupero vida");

        std::cout << player->getName()
                  << " usa "
                  << potion->getName()
                  << ", vida actual: "
                  << player->getHealth() << '\n';
    }

    Item* treasure = inventory.findItem("Ancient Crown");
    if (treasure != nullptr) {
        treasure->use(*player);
        logger->writeLog("Chris uso Ancient Crown y aumento su puntaje");

        std::cout << player->getName()
                  << " usa "
                  << treasure->getName()
                  << ", puntaje actual: "
                  << player->getScore() << '\n';
    }

    Item* key = inventory.findItem("Golden Key");
    if (key != nullptr) {
        key->use(*player);
        logger->writeLog("Chris uso Golden Key");

        std::cout << player->getName()
                  << " usa "
                  << key->getName() << '\n';
    }

    rewardEvent.trigger(*player, *logger);

    player->moveTo(dragonLair);
    currentRoom = player->getCurrentRoom();

    std::cout << "\n" << player->getName()
              << " se mueve a "
              << currentRoom->getName() << '\n';

    logger->writeLog("Chris se movio a " + currentRoom->getName());

    std::cout << "\n===== COMBATE =====\n";

    if (currentRoom->hasEnemies()) {
        Enemy* dragon = currentRoom->getEnemies()[0].get();

        std::cout << player->getName()
                  << " encuentra a "
                  << dragon->getName() << '\n';

        logger->writeLog("Chris encontro a " + dragon->getName());

        while (player->isAlive() && dragon->isAlive()) {
            player->attack(*dragon);
            logger->writeLog("Chris ataco a " + dragon->getName());

            std::cout << player->getName()
                      << " ataca a "
                      << dragon->getName()
                      << " | Vida de "
                      << dragon->getName()
                      << ": "
                      << dragon->getHealth() << '\n';

            if (!dragon->isAlive()) {
                break;
            }

            partner.attack(*dragon);
            logger->writeLog("Jimena ataco a " + dragon->getName());

            std::cout << partner.getName()
                      << " ataca a "
                      << dragon->getName()
                      << " | Vida de "
                      << dragon->getName()
                      << ": "
                      << dragon->getHealth() << '\n';

            if (!dragon->isAlive()) {
                break;
            }

            dragon->specialAttack(*player);
            logger->writeLog(dragon->getName() + " uso ataque especial contra Chris");

            std::cout << dragon->getName()
                      << " usa ataque especial"
                      << " | Vida de "
                      << player->getName()
                      << ": "
                      << player->getHealth() << '\n';
        }

        if (player->isAlive()) {
            player->addScore(dragon->getReward());
            logger->writeLog("Chris y Jimena derrotaron a " + dragon->getName());
            logger->writeLog("Chris recibio la recompensa del enemigo");

            std::cout << "\n"
                      << dragon->getName()
                      << " fue derrotado\n";

            std::cout << "Puntaje final de "
                      << player->getName()
                      << ": "
                      << player->getScore()
                      << "\n";
        } else {
            logger->writeLog("Chris fue derrotado por " + dragon->getName());
            std::cout << "\nChris fue derrotado\n";
        }
    }

    if (checkEndCondition()) {
        logger->writeLog("El objetivo principal fue completado");
    }

    finished = true;
}

bool SimulationEngine::checkEndCondition() {
    Player* player = world->getPlayer();

    if (player == nullptr) {
        return false;
    }

    return objective.check(*player);
}

bool SimulationEngine::isFinished() const {
    return finished;
}