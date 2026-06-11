#ifndef PROYECTO2_ENEMY_H
#define PROYECTO2_ENEMY_H

#include "entities/Character.h"

class Player;

class Enemy : public Character {
private:
    std::string type;
    int reward;

public:
    Enemy(const std::string& name,
          const std::string& type,
          int health,
          int attackPower,
          int reward);

    const std::string& getType() const;
    int getReward() const;

    void setType(const std::string& type);
    void setReward(int reward);

    void specialAttack(Player& player) const;

};

#endif