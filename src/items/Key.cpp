#include "items/Key.h"

#include <stdexcept>

Key::Key(const std::string& name,
         int value,
         int targetRoomId)
    : Item(name, value),
      targetRoomId(targetRoomId) {

    if (targetRoomId < 0) {
        throw std::invalid_argument("El identificador de la habitacion no puede ser negativo");
    }
}

int Key::getTargetRoomId() const {
    return targetRoomId;
}

void Key::use(Player&) {
}