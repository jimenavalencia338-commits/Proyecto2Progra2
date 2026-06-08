#include "items/Potion.h"
#include "entities/Player.h"

#include <stdexcept>

Potion::Potion(const std::string& name,
               int value,
               int healAmount)
    : Item(name, value),
      healAmount(healAmount) {

    if (healAmount < 0) {
        throw std::invalid_argument("La cantidad de curacion no puede ser negativa");
    }
}

int Potion::getHealAmount() const {
    return healAmount;
}

void Potion::use(Player& player) {
    player.setHealth(
        player.getHealth() + healAmount
    );
}