#include "../../include/events/TrapEvent.h"

TrapEvent::TrapEvent(
    const string& description,
    int damage)
    : GameEvent(description),
      damage(damage) {
}

void TrapEvent::trigger(Player& player, Logger& logger) {
    activated = true;

    // Se implementará cuando Player y Logger estén listos
}

int TrapEvent::getDamage() const {
    return damage;
}