#include "items/Treasure.h"
#include "entities/Player.h"

#include <stdexcept>

Treasure::Treasure(const std::string& name,
                   int value,
                   const std::string& rarity)
    : Item(name, value),
      rarity(rarity) {

    if (rarity.empty()) {
        throw std::invalid_argument("La rareza no puede estar vacia");
    }
}

const std::string& Treasure::getRarity() const {
    return rarity;
}

void Treasure::use(Player& player) {
    player.addScore(value);
}