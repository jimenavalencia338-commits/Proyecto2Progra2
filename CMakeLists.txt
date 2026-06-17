cmake_minimum_required(VERSION 4.1)
project(Proyecto2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Proyecto2
        main.cpp
        src/entities/Character.cpp
        src/entities/Player.cpp
        src/entities/Enemy.cpp
        src/items/Item.cpp
        src/items/Potion.cpp
        src/items/Key.cpp
        src/items/Treasure.cpp
        src/items/Inventory.cpp
        src/world/Room.cpp
        src/world/World.cpp

        src/events/GameEvent.cpp
        src/events/TrapEvent.cpp
        src/events/RewardEvent.cpp

        src/objectives/Objective.cpp

        src/utils/FileManager.cpp
        src/utils/Logger.cpp
        src/utils/ReportGenerator.cpp

        src/exceptions/GameException.cpp
        src/exceptions/FileException.cpp
        src/exceptions/InvalidDataException.cpp
        src/exceptions/SimulationException.cpp

        src/engine/AdventureEngine.cpp
        src/engine/SimulationEngine.cpp
        src/items/Inventory.cpp
        include/items/Inventory.h
)

target_include_directories(Proyecto2 PRIVATE include)