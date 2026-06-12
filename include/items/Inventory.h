#pragma once

#include "items/Item.h"

#include <memory>
#include <string>
#include <vector>

class Inventory {
private:
    std::vector<std::unique_ptr<Item>> items;

public:
    Inventory() = default;

    void addItem(std::unique_ptr<Item> item);

    std::unique_ptr<Item> removeItem(const std::string& itemName);

    Item* findItem(const std::string& itemName) const;

    bool hasItem(const std::string& itemName) const;

    void listItems() const;

    bool isEmpty() const;

    int size() const;
};

