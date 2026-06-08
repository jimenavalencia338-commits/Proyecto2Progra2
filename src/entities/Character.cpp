#include "entities/Character.h"

#include <stdexcept>

Character::Character(const std::string& name, int health, int attackPower)
    : name(name), health(health), attackPower(attackPower) {
    if (name.empty()) {
        throw std::invalid_argument("El nombre del personaje no puede estar vacio");
    }
    if (health < 0) {
        throw std::invalid_argument("La vida del personaje no puede ser negativa");
    }
    if (attackPower < 0) {
        throw std::invalid_argument("El poder de ataque no puede ser negativo");
    }
}

const std::string& Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return health;
}

int Character::getAttackPower() const {
    return attackPower;
}

void Character::setName(const std::string& name) {
    if (name.empty()) {
        throw std::invalid_argument("El nombre del personaje no puede estar vacio");
    }

    this->name = name;
}

void Character::setHealth(int health) {
    if (health < 0) {
        throw std::invalid_argument("La vida del personaje no puede ser negativa");
    }

    this->health = health;
}

void Character::setAttackPower(int attackPower) {
    if (attackPower < 0) {
        throw std::invalid_argument("El poder de ataque no puede ser negativo");
    }

    this->attackPower = attackPower;
}

bool Character::isAlive() const {
    return health > 0;
}

void Character::receiveDamage(int amount) {
    if (amount < 0) {
        throw std::invalid_argument("La cantidad de dano no puede ser negativa");
    }

    health -= amount;

    if (health < 0) {
        health = 0;
    }
}

void Character::attack(Character& target) const {
    if (!isAlive()) {
        return;
    }

    target.receiveDamage(attackPower);

}