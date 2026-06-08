#include "../../include/objectives/Objective.h"

Objective::Objective(const string& description)
        : description(description),
          completed(false) {
}

bool Objective::check(Player& player) {
    // Se implementará cuando conozcamos Player
    return completed;
}

void Objective::complete() {
    completed = true;
}

bool Objective::isCompleted() const {
    return completed;
}