#ifndef PROYECTO2_POTION_H
#define PROYECTO2_POTION_H

#include "items/Item.h"

class Potion : public Item {
private:
    int healAmount;

public:
    Potion(const std::string& name,
           int value,
           int healAmount);

    int getHealAmount() const;

    void use(Player& player) override;
};

#endif