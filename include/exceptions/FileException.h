#ifndef PROYECTO2_FILE_EXCEPTION_H
#define PROYECTO2_FILE_EXCEPTION_H

#include "exceptions/GameException.h"

class FileException : public GameException {
public:
    explicit FileException(const std::string& message);
};

#endif