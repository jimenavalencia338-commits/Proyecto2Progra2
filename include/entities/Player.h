#pragma once

#include "entities/Character.h"

class Room;

class Player : public Character {
private:
    int score;
    Room* currentRoom;

public:
    explicit Player(const std::string& name);

    int getScore() const;
    Room* getCurrentRoom() const;

    void setCurrentRoom(Room* room);
    void addScore(int points);

    void moveTo(Room* room);

};

