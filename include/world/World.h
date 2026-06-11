//
// Created by jimen on 7/6/2026.
//
#pragma once

#include <vector>
#include <memory>

using namespace std;

class Room;
class Player;
class GameEvent;

class World {
private:
    vector<unique_ptr<Room>> rooms;
    unique_ptr<Player> player;
    vector<unique_ptr<GameEvent>> events;

public:
    World();

    void addRoom(unique_ptr<Room> room);

    Room* getRoomById(int id);

    void setPlayer(unique_ptr<Player> player);

    Player* getPlayer();

    vector<unique_ptr<GameEvent>>& getEvents();
    vector<unique_ptr<Room>>& getRooms();
};