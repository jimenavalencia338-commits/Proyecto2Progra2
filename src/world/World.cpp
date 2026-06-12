#include "world/World.h"

#include <utility>

World::World() {
}

void World::addRoom(unique_ptr<Room> room) {
    rooms.push_back(move(room));
}

Room* World::getRoomById(int id) {
    for(auto& room : rooms) {
        if(room->getId() == id) {
            return room.get();
        }
    }

    return nullptr;
}

void World::setPlayer(unique_ptr<Player> player) {
    this->player = move(player);
}

Player* World::getPlayer() {
    return player.get();
}

vector<unique_ptr<GameEvent>>& World::getEvents() {
    return events;
}

vector<unique_ptr<Room>>& World::getRooms() {
    return rooms;
}