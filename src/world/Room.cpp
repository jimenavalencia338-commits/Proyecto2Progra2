#include "world/Room.h"

#include <utility>

Room::Room(int id, const std::string& name, const std::string& description)
    : id(id), name(name), description(description) {
}

int Room::getId() const {
    return id;
}

std::string Room::getName() const {
    return name;
}

std::string Room::getDescription() const {
    return description;
}

std::vector<Room*>& Room::getConnectedRooms() {
    return connectedRooms;
}

std::vector<std::unique_ptr<Item>>& Room::getItems() {
    return items;
}

std::vector<std::unique_ptr<Enemy>>& Room::getEnemies() {
    return enemies;
}

void Room::connectRoom(Room* room) {
    connectedRooms.push_back(room);
}

void Room::addItem(std::unique_ptr<Item> item) {
    items.push_back(std::move(item));
}

void Room::addEnemy(std::unique_ptr<Enemy> enemy) {
    enemies.push_back(std::move(enemy));
}

void Room::removeItem(int index) {
    if (index >= 0 && index < static_cast<int>(items.size())) {
        items.erase(items.begin() + index);
    }
}

bool Room::hasEnemies() const {
    return !enemies.empty();
}