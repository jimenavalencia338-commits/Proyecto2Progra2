#include "entities/Enemy.h"
#include "entities/Player.h"

#include <stdexcept>

Enemy::Enemy(const std::string& name,
             const std::string& type,
             int health,
             int attackPower,
             int reward)
    : Character(name, health, attackPower),
      type(type),
      reward(reward) {

    if (type.empty()) {
        throw std::invalid_argument("El tipo de enemigo no puede estar vacio");
    }

    if (reward < 0) {
        throw std::invalid_argument("La recompensa no puede ser negativa");
    }
}

const std::string& Enemy::getType() const {
    return type;
}

int Enemy::getReward() const {
    return reward;
}

void Enemy::setType(const std::string& type) {
    if (type.empty()) {
        throw std::invalid_argument("El tipo de enemigo no puede estar vacio");
    }

    this->type = type;
}

void Enemy::setReward(int reward) {
    if (reward < 0) {
        throw std::invalid_argument("La recompensa no puede ser negativa");
    }

    this->reward = reward;
}

void Enemy::specialAttack(Player& player) const {
    if (!isAlive()) {
        return;
    }

    player.receiveDamage(attackPower + 5);

}