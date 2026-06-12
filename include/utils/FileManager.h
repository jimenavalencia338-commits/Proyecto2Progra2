#pragma once

#include "world/World.h"

#include <filesystem>
#include <string>

class FileManager {
public:
    FileManager();

    bool validateFile(const std::string& path) const;

    void createBaseFiles(const std::filesystem::path& dataPath) const;

    void loadWorld(World& world, const std::filesystem::path& dataPath) const;

private:
    void loadRooms(World& world, const std::filesystem::path& dataPath) const;
    void loadConnections(World& world, const std::filesystem::path& dataPath) const;
    void loadItems(World& world, const std::filesystem::path& dataPath) const;
    void loadEnemies(World& world, const std::filesystem::path& dataPath) const;
};