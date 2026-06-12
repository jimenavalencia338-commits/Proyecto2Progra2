#pragma once

#include "exceptions/GameException.h"

class InvalidDataException : public GameException {
public:
    explicit InvalidDataException(const std::string& message);
};

