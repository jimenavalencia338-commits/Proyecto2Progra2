#pragma once

#include <string>
#include <vector>
#include <memory>

using namespace std;

class Item;
class Enemy;

class Room {
private:
    int id;
    string name;
    string description;

    vector<Room*> connectedRooms;
    vector<unique_ptr<Item>> items;
    vector<unique_ptr<Enemy>> enemies;

public:
    Room(int id, const string& name, const string& description);

    int getId() const;
    string getName() const;
    string getDescription() const;

    vector<Room*>& getConnectedRooms();
    vector<unique_ptr<Item>>& getItems();
    vector<unique_ptr<Enemy>>& getEnemies();

    void connectRoom(Room* room);
    void addItem(unique_ptr<Item> item);
    void addEnemy(unique_ptr<Enemy> enemy);
    void removeItem(int index);

    bool hasEnemies() const;
};