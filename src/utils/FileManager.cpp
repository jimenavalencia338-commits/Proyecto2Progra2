#include "utils/FileManager.h"

#include "items/Potion.h"
#include "items/Key.h"
#include "items/Treasure.h"
#include "entities/Enemy.h"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

static std::vector<std::string> splitLine(const std::string& line, char delimiter) {
    std::vector<std::string> parts;
    std::stringstream stream(line);
    std::string part;

    while (std::getline(stream, part, delimiter)) {
        parts.push_back(part);
    }

    return parts;
}

FileManager::FileManager() {
}

bool FileManager::validateFile(const std::string& path) const {
    std::ifstream file(path);
    return file.good();
}

void FileManager::createBaseFiles(const std::filesystem::path& dataPath) const {
    std::filesystem::create_directories(dataPath);

    if (!std::filesystem::exists(dataPath / "rooms.txt")) {
        std::ofstream file(dataPath / "rooms.txt");

        file << "1|Entrance|Inicio de la mazmorra\n";
        file << "2|Hallway|Pasillo oscuro\n";
        file << "3|Treasure Room|Sala del tesoro\n";
        file << "4|Dragon Lair|Guarida del dragon\n";
    }

    if (!std::filesystem::exists(dataPath / "connections.txt")) {
        std::ofstream file(dataPath / "connections.txt");

        file << "1|2\n";
        file << "2|3\n";
        file << "3|4\n";
    }

    if (!std::filesystem::exists(dataPath / "items.txt")) {
        std::ofstream file(dataPath / "items.txt");

        file << "1|Potion|Small Potion|25|30\n";
        file << "3|Treasure|Ancient Crown|150|Legendary\n";
        file << "3|Key|Golden Key|50|4\n";
    }

    if (!std::filesystem::exists(dataPath / "enemies.txt")) {
        std::ofstream file(dataPath / "enemies.txt");

        file << "4|Drogon|Dragon|45|25|150\n";
    }
}

void FileManager::loadWorld(World& world, const std::filesystem::path& dataPath) const {
    loadRooms(world, dataPath);
    loadConnections(world, dataPath);
    loadItems(world, dataPath);
    loadEnemies(world, dataPath);
}

void FileManager::loadRooms(World& world, const std::filesystem::path& dataPath) const {
    std::ifstream file(dataPath / "rooms.txt");

    if (!file.is_open()) {
        throw std::runtime_error("No se pudo abrir rooms.txt");
    }

    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        std::vector<std::string> parts = splitLine(line, '|');

        if (parts.size() != 3) {
            throw std::runtime_error("Formato invalido en rooms.txt");
        }

        int id = std::stoi(parts[0]);
        world.addRoom(std::make_unique<Room>(id, parts[1], parts[2]));
    }
}

void FileManager::loadConnections(World& world, const std::filesystem::path& dataPath) const {
    std::ifstream file(dataPath / "connections.txt");

    if (!file.is_open()) {
        throw std::runtime_error("No se pudo abrir connections.txt");
    }

    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        std::vector<std::string> parts = splitLine(line, '|');

        if (parts.size() != 2) {
            throw std::runtime_error("Formato invalido en connections.txt");
        }

        Room* fromRoom = world.getRoomById(std::stoi(parts[0]));
        Room* toRoom = world.getRoomById(std::stoi(parts[1]));

        if (fromRoom == nullptr || toRoom == nullptr) {
            throw std::runtime_error("Conexion invalida entre habitaciones");
        }

        fromRoom->connectRoom(toRoom);
        toRoom->connectRoom(fromRoom);
    }
}

void FileManager::loadItems(World& world, const std::filesystem::path& dataPath) const {
    std::ifstream file(dataPath / "items.txt");

    if (!file.is_open()) {
        throw std::runtime_error("No se pudo abrir items.txt");
    }

    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        std::vector<std::string> parts = splitLine(line, '|');

        if (parts.size() != 5) {
            throw std::runtime_error("Formato invalido en items.txt");
        }

        int roomId = std::stoi(parts[0]);
        std::string type = parts[1];
        std::string name = parts[2];
        int value = std::stoi(parts[3]);

        Room* room = world.getRoomById(roomId);

        if (room == nullptr) {
            throw std::runtime_error("Item asignado a una habitacion inexistente");
        }

        if (type == "Potion") {
            int healAmount = std::stoi(parts[4]);
            room->addItem(std::make_unique<Potion>(name, value, healAmount));
        } else if (type == "Treasure") {
            room->addItem(std::make_unique<Treasure>(name, value, parts[4]));
        } else if (type == "Key") {
            int targetRoomId = std::stoi(parts[4]);
            room->addItem(std::make_unique<Key>(name, value, targetRoomId));
        } else {
            throw std::runtime_error("Tipo de item desconocido");
        }
    }
}

void FileManager::loadEnemies(World& world, const std::filesystem::path& dataPath) const {
    std::ifstream file(dataPath / "enemies.txt");

    if (!file.is_open()) {
        throw std::runtime_error("No se pudo abrir enemies.txt");
    }

    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        std::vector<std::string> parts = splitLine(line, '|');

        if (parts.size() != 6) {
            throw std::runtime_error("Formato invalido en enemies.txt");
        }

        int roomId = std::stoi(parts[0]);
        Room* room = world.getRoomById(roomId);

        if (room == nullptr) {
            throw std::runtime_error("Enemigo asignado a una habitacion inexistente");
        }

        room->addEnemy(std::make_unique<Enemy>(
                parts[1],
                parts[2],
                std::stoi(parts[3]),
                std::stoi(parts[4]),
                std::stoi(parts[5])
        ));
    }
}