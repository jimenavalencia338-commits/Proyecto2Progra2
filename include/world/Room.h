#pragma once

#include "items/Item.h"
#include "entities/Enemy.h"

#include <memory>
#include <string>
#include <vector>

class Room {
private:
    int id;
    std::string name;
    std::string description;

    std::vector<Room*> connectedRooms;
    std::vector<std::unique_ptr<Item>> items;
    std::vector<std::unique_ptr<Enemy>> enemies;

public:
    Room(int id, const std::string& name, const std::string& description);

    int getId() const;
    std::string getName() const;
    std::string getDescription() const;

    std::vector<Room*>& getConnectedRooms();
    std::vector<std::unique_ptr<Item>>& getItems();
    std::vector<std::unique_ptr<Enemy>>& getEnemies();

    void connectRoom(Room* room);
    void addItem(std::unique_ptr<Item> item);
    void addEnemy(std::unique_ptr<Enemy> enemy);
    void removeItem(int index);

    bool hasEnemies() const;
};