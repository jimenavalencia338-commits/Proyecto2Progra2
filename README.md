# Proyecto II - Simulación de Mazmorra

## Universidad Nacional de Costa Rica
### Facultad de Ciencias Exactas y Naturales
### Escuela de Informática
### EIF204 - Programación II

**Profesor:** Luis Elías Mora Montero

**Integrantes:**

- Chris Martínez Sánchez — 119550022
- Jimena Valencia Montero — 402710618

---

# Descripción General

Este proyecto consiste en una simulación de aventura desarrollada en C++ utilizando los principios de Programación Orientada a Objetos.

La aplicación permite cargar información desde archivos de texto para construir un mundo compuesto por habitaciones, objetos, enemigos y eventos. Durante la ejecución, el jugador explora la mazmorra, recolecta objetos, activa eventos, enfrenta enemigos y completa objetivos definidos por el sistema.

Al finalizar la aventura, se genera automáticamente una bitácora de acontecimientos y un reporte final con los resultados obtenidos.

---

# Objetivo del Proyecto

Desarrollar una aplicación modular que integre los conceptos fundamentales estudiados en el curso de Programación II, incluyendo programación orientada a objetos, herencia, polimorfismo, manejo de excepciones, manejo de archivos, uso de smart pointers y modularización del código.

---

# Características Implementadas

- Carga automática de información desde archivos
- Creación automática de archivos iniciales
- Gestión de habitaciones conectadas
- Inventario de objetos
- Sistema de exploración
- Sistema de combate
- Eventos especiales
- Objetivos de misión
- Bitácora de acontecimientos
- Reporte final de la aventura
- Validación de datos
- Manejo de errores mediante excepciones personalizadas

---

# Estructura del Proyecto

```text
Proyecto2
├── include
│   ├── engine
│   ├── entities
│   ├── events
│   ├── exceptions
│   ├── items
│   ├── objectives
│   ├── utils
│   └── world
├── src
│   ├── engine
│   ├── entities
│   ├── events
│   ├── exceptions
│   ├── items
│   ├── objectives
│   ├── utils
│   └── world
├── data
│   ├── rooms.txt
│   ├── connections.txt
│   ├── items.txt
│   └── enemies.txt
├── output
│   ├── log.txt
│   └── final_report.txt
├── main.cpp
├── CMakeLists.txt
└── README.md
