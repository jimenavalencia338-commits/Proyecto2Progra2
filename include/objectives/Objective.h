#pragma once

#include <string>

using namespace std;

class Player;

class Objective {
private:
    string description;
    bool completed;

public:
    Objective(const string& description);

    bool check(Player& player);

    void complete();

    bool isCompleted() const;
};