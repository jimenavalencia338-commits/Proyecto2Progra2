#pragma once

#include "exceptions/GameException.h"

class FileException : public GameException {
public:
    explicit FileException(const std::string& message);
};

