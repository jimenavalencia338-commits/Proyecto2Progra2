#include "events/TrapEvent.h"
#include "entities/Player.h"
#include "utils/Logger.h"

TrapEvent::TrapEvent(
    const string& description,
    int damage)
    : GameEvent(description),
      damage(damage) {
}

void TrapEvent::trigger(Player& player, Logger& logger) {
    if (activated) {
        return;
    }

    player.receiveDamage(damage);
    logger.writeLog(description);

    activated = true;
}

int TrapEvent::getDamage() const {
    return damage;
}