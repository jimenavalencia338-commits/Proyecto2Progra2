#include "../../include/world/Room.h"

Room::Room(int id, const string& name, const string& description)
        : id(id), name(name), description(description) {
}

int Room::getId() const {
    return id;
}

string Room::getName() const {
    return name;
}

string Room::getDescription() const {
    return description;
}

vector<Room*>& Room::getConnectedRooms() {
    return connectedRooms;
}

vector<unique_ptr<Item>>& Room::getItems() {
    return items;
}

vector<unique_ptr<Enemy>>& Room::getEnemies() {
    return enemies;
}

void Room::connectRoom(Room* room) {
    connectedRooms.push_back(room);
}

void Room::addItem(unique_ptr<Item> item) {
    items.push_back(move(item));
}

void Room::addEnemy(unique_ptr<Enemy> enemy) {
    enemies.push_back(move(enemy));
}

void Room::removeItem(int index) {
    if(index >= 0 && index < items.size()) {
        items.erase(items.begin() + index);
    }
}

bool Room::hasEnemies() const {
    return !enemies.empty();
}