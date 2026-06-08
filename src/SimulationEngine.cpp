#include "engine/SimulationEngine.h"

#include "exceptions/SimulationException.h"

SimulationEngine::SimulationEngine()
    : world(nullptr), logger(nullptr), finished(false) {
}

void SimulationEngine::setWorld(World* world) {
    if (world == nullptr) {
        throw SimulationException("El mundo de la simulacion no puede ser nulo");
    }

    this->world = world;
}

void SimulationEngine::setLogger(Logger* logger) {
    if (logger == nullptr) {
        throw SimulationException("El logger de la simulacion no puede ser nulo");
    }

    this->logger = logger;
}

void SimulationEngine::start() {
    if (world == nullptr) {
        throw SimulationException("No se puede iniciar la simulacion sin un mundo");
    }

    finished = false;
}

void SimulationEngine::processTurn() {
    if (world == nullptr) {
        throw SimulationException("No se puede procesar un turno sin un mundo");
    }

    if (finished) {
        return;
    }

    finished = checkEndCondition();
}

bool SimulationEngine::checkEndCondition() const {
    return false;
}

bool SimulationEngine::isFinished() const {
    return finished;
}