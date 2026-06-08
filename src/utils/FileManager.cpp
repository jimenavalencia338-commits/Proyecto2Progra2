#include "../../include/utils/FileManager.h"
#include <fstream>

FileManager::FileManager() {
}

bool FileManager::validateFile(const string& path) {
    ifstream file(path);
    return file.good();
}

void FileManager::loadWorld(const string& path) {
}

void FileManager::loadRooms(const string& path) {
}

void FileManager::loadItems(const string& path) {
}

void FileManager::loadEnemies(const string& path) {
}