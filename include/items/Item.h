#ifndef PROYECTO2_ITEM_H
#define PROYECTO2_ITEM_H

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

#endif