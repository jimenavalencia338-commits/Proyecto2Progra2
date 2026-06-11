#pragma once

#include <string>

using namespace std;

class World;

class FileManager {
public:
    FileManager();

    bool validateFile(const string& path);

    void loadWorld(const string& path);
    void loadRooms(const string& path);
    void loadItems(const string& path);
    void loadEnemies(const string& path);
};

