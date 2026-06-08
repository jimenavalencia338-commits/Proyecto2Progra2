#include "exceptions/SimulationException.h"

SimulationException::SimulationException(const std::string& message)
    : GameException(message) {
}