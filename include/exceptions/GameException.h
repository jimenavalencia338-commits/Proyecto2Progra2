#ifndef PROYECTO2_GAME_EXCEPTION_H
#define PROYECTO2_GAME_EXCEPTION_H

#include <stdexcept>
#include <string>

class GameException : public std::runtime_error {
public:
    explicit GameException(const std::string& message);
};

#endif