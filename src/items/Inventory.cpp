#include "items/Inventory.h"

#include <iostream>
#include <stdexcept>

void Inventory::addItem(std::unique_ptr<Item> item) {
    if (item == nullptr) {
        throw std::invalid_argument(
                "No se puede agregar un objeto nulo al inventario"
        );
    }

    items.push_back(std::move(item));
}

std::unique_ptr<Item> Inventory::removeItem(const std::string& itemName) {
    if (itemName.empty()) {
        throw std::invalid_argument(
                "El nombre del objeto no puede estar vacio"
        );
    }

    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->getName() == itemName) {

            std::unique_ptr<Item> removedItem = std::move(*it);

            items.erase(it);

            return removedItem;
        }
    }

    return nullptr;
}

Item* Inventory::findItem(const std::string& itemName) const {
    if (itemName.empty()) {
        throw std::invalid_argument(
                "El nombre del objeto no puede estar vacio"
        );
    }

    for (const auto& item : items) {
        if (item->getName() == itemName) {
            return item.get();
        }
    }

    return nullptr;
}

bool Inventory::hasItem(const std::string& itemName) const {
    return findItem(itemName) != nullptr;
}

void Inventory::listItems() const {
    if (items.empty()) {
        std::cout << "El inventario esta vacio\n";
        return;
    }

    for (const auto& item : items) {
        std::cout
                << "- "
                << item->getName()
                << " | Valor: "
                << item->getValue()
                << '\n';
    }
}

bool Inventory::isEmpty() const {
    return items.empty();
}

int Inventory::size() const {
    return static_cast<int>(items.size());
}