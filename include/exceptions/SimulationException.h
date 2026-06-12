#pragma once

#include "exceptions/GameException.h"

class SimulationException : public GameException {
public:
    explicit SimulationException(const std::string& message);
};

