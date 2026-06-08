#include "entities/Player.h"

#include <stdexcept>

Player::Player(const std::string& name)
    : Character(name, 100, 15), score(0), currentRoom(nullptr) {
}

int Player::getScore() const {
    return score;
}

Room* Player::getCurrentRoom() const {
    return currentRoom;
}

void Player::setCurrentRoom(Room* room) {
    currentRoom = room;
}

void Player::addScore(int points) {
    if (points < 0) {
        throw std::invalid_argument("Los puntos no pueden ser negativos");
    }

    score += points;
}

void Player::moveTo(Room* room) {
    if (room == nullptr) {
        throw std::invalid_argument("No se puede mover a una habitacion nula");
    }

    currentRoom = room;

}