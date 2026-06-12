#pragma once

#include "items/Item.h"

class Treasure : public Item {
private:
    std::string rarity;

public:
    Treasure(const std::string& name,
             int value,
             const std::string& rarity);

    const std::string& getRarity() const;

    void use(Player& player) override;
};
