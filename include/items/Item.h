#pragma once

#include <string>

class Player;

class Item {
protected:
    std::string name;
    int value;

public:
    Item(const std::string& name, int value);
    virtual ~Item() = default;

    const std::string& getName() const;
    int getValue() const;

    virtual void use(Player& player) = 0;
};

