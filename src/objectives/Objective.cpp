#include "objectives/Objective.h"
#include "entities/Player.h"


Objective::Objective(const string& description)
        : description(description),
          completed(false) {
}

bool Objective::check(Player& player) {
    if (player.isAlive() && player.getScore() >= 300) {
        complete();
    }
    return completed;
}

void Objective::complete() {
    completed = true;
}

bool Objective::isCompleted() const {
    return completed;
}