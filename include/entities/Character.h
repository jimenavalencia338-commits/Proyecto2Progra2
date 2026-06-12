#pragma once

#include <string>

class Character {
protected:
    std::string name;
    int health;
    int attackPower;

public:
    Character(const std::string& name, int health, int attackPower);
    virtual ~Character() = default;

    const std::string& getName() const;
    int getHealth() const;
    int getAttackPower() const;

    void setName(const std::string& name);
    void setHealth(int health);
    void setAttackPower(int attackPower);

    bool isAlive() const;
    void receiveDamage(int amount);

    virtual void attack(Character& target) const;

};
