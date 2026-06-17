Technical Document P02 EIF-204

General Description

This project consists of an adventure simulation engine developed in C++. The system represents a world composed of rooms, entities, items, events and objectives.

Players explore different rooms, collect items, activate events, complete objectives and fight enemies while interacting with the adventure world. The system applies Object-Oriented Programming principles such as encapsulation, inheritance, polymorphism and exception handling.

⸻

Theme

Fantasy Adventure Simulation

The player explores a world composed of interconnected rooms, collects treasures and useful items, activates events, avoids traps and defeats enemies while progressing through the adventure.

⸻

Main Classes
---------------------------
World:

Represents the complete adventure world and stores the available rooms.

Room:

Represents a location within the world. Rooms may contain items, enemies and events.

Player:

Represents the main character controlled during the simulation.

Enemy:

Represents hostile entities that can engage in combat with players.

Item:

Represents collectible objects that can provide benefits or special effects.

GameEvent:

Base class for all events in the system.

TrapEvent:

Specialized event that negatively affects the player.

RewardEvent:

Specialized event that grants rewards or bonuses.

Objective:

Represents goals that can be completed during the adventure.

AdventureEngine:

Controls the adventure flow and interactions between game components.

SimulationEngine:

Coordinates and executes the complete simulation process.

⸻

Input Files:

The system uses files located inside the data directory.

These files store information required by the simulation and allow data persistence between executions.

⸻

Output Files:

The system generates output files inside the output directory.

Generated files include:

* log.txt
* final_report.txt

These files record simulation events and summarize the final results of the adventure.

⸻
------
Design Decisions

The project was designed using Object-Oriented Programming principles.

Main design decisions include:

* Separation of responsibilities through specialized classes.
* Use of inheritance for entities, events and other extensible components.
* Use of polymorphism to support different event and item behaviors.
* Exception handling to validate invalid operations.
* Modular architecture to facilitate future expansion.

⸻

Testing

The system was tested through a complete adventure simulation.

Tests included:

* Character creation validation.
* Enemy creation validation.
* Inventory management.
* Item collection and usage.
* Event activation.
* Combat execution.
* Exception handling.
* File generation verification.

The simulation completed successfully and finished with exit code 0.

⸻

Future Improvements

Possible future improvements include:

* Additional room types.
* More enemy classes.
* Expanded combat mechanics.
* Save and load game functionality.
* Graphical user interface.
* Dynamic objective generation.
* Additional item and event types.
* More complex world generation systems.