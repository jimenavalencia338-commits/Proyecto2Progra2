#include "items/Item.h"

#include <stdexcept>

Item::Item(const std::string& name, int value)
    : name(name), value(value) {

    if (name.empty()) {
        throw std::invalid_argument("El nombre del objeto no puede estar vacio");
    }

    if (value < 0) {
        throw std::invalid_argument("El valor del objeto no puede ser negativo");
    }
}

const std::string& Item::getName() const {
    return name;
}

int Item::getValue() const {
    return value;
}