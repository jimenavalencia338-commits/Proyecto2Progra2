#ifndef PROYECTO2_SIMULATION_EXCEPTION_H
#define PROYECTO2_SIMULATION_EXCEPTION_H

#include "exceptions/GameException.h"

class SimulationException : public GameException {
public:
    explicit SimulationException(const std::string& message);
};

#endif