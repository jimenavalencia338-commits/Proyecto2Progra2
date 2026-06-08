#include "../../include/events/GameEvent.h"

GameEvent::GameEvent(const string& description)
    : description(description), activated(false) {
}

bool GameEvent::isActivated() const {
    return activated;
}