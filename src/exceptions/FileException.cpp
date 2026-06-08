#include "exceptions/FileException.h"

FileException::FileException(const std::string& message)
    : GameException(message) {
}