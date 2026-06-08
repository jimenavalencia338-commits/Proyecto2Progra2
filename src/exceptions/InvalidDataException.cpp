#include "exceptions/InvalidDataException.h"

InvalidDataException::InvalidDataException(const std::string& message)
    : GameException(message) {
}