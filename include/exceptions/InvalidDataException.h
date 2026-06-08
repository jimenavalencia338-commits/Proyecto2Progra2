#ifndef PROYECTO2_INVALID_DATA_EXCEPTION_H
#define PROYECTO2_INVALID_DATA_EXCEPTION_H

#include "exceptions/GameException.h"

class InvalidDataException : public GameException {
public:
    explicit InvalidDataException(const std::string& message);
};

#endif