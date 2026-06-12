#pragma once

#include "world/Room.h"
#include "entities/Player.h"
#include "events/GameEvent.h"

#include <memory>
#include <vector>

class World {
private:
    std::vector<std::unique_ptr<Room>> rooms;
    std::unique_ptr<Player> player;
    std::vector<std::unique_ptr<GameEvent>> events;

public:
    World();

    void addRoom(std::unique_ptr<Room> room);

    Room* getRoomById(int id);

    void setPlayer(std::unique_ptr<Player> player);

    Player* getPlayer();

    std::vector<std::unique_ptr<GameEvent>>& getEvents();
    std::vector<std::unique_ptr<Room>>& getRooms();
};