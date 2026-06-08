#include "exceptions/GameException.h"

GameException::GameException(const std::string& message)
    : std::runtime_error(message) {
}