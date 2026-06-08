cmake_minimum_required(VERSION 4.1)
project(Proyecto2)

set(CMAKE_CXX_STANDARD 26)

add_executable(Proyecto2
        main.cpp
        src/entities/Character.cpp
        src/entities/Player.cpp
        src/entities/Enemy.cpp
        include/items/Item.h
        include/items/Potion.h
        include/items/Key.h
        include/items/Treasure.h
)

target_include_directories(Proyecto2 PRIVATE include)