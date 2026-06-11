#ifndef PROYECTO2_KEY_H
#define PROYECTO2_KEY_H

#include "items/Item.h"

class Key : public Item {
private:
    int targetRoomId;

public:
    Key(const std::string& name,
        int value,
        int targetRoomId);

    int getTargetRoomId() const;

    void use(Player& player) override;
};

#endif