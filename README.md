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

Desarrollar una aplicación modular que integre los conceptos fundamentales estudiados en el curso de Programación II, incluyendo:

- Programación Orientada a Objetos.
- Herencia.
- Polimorfismo.
- Encapsulamiento.
- Composición.
- Manejo de Excepciones.
- Manejo de Archivos.
- Uso de Smart Pointers.
- Modularización del código.
- Diagramas UML.

---

# Características Implementadas

- Carga automática de información desde archivos.
- Creación automática de archivos iniciales.
- Gestión de habitaciones conectadas.
- Inventario de objetos.
- Sistema de exploración.
- Sistema de combate.
- Eventos especiales.
- Objetivos de misión.
- Bitácora de acontecimientos.
- Reporte final de la aventura.
- Validación de datos.
- Manejo de errores mediante excepciones personalizadas.

---

# Arquitectura del Sistema

La aplicación está organizada en módulos especializados para separar responsabilidades y facilitar el mantenimiento.

## Engine

### AdventureEngine

Controlador principal del sistema.

**Responsabilidades:**

- Cargar datos.
- Ejecutar la simulación.
- Generar reportes.

### SimulationEngine

Administra la lógica principal de la aventura.

**Responsabilidades:**

- Movimiento del jugador.
- Eventos especiales.
- Combate.
- Objetivos.
- Finalización de la simulación.

---

## World

### World

Representa el mundo del juego y administra:

- Habitaciones.
- Jugador principal.
- Eventos.

### Room

Representa una habitación de la mazmorra.

Cada habitación puede contener:

- Habitaciones conectadas.
- Objetos.
- Enemigos.

---

## Entities

### Character

Clase abstracta base para todos los personajes.

### Player

Representa al jugador principal.

### Enemy

Representa a los enemigos presentes en la aventura.

---

## Items

### Item

Clase abstracta base para los objetos.

### Potion

Permite recuperar puntos de vida.

### Key

Permite acceder a nuevas áreas.

### Treasure

Otorga puntos de recompensa.

### Inventory

Administra los objetos recolectados durante la aventura.

---

## Events

### GameEvent

Clase abstracta base para eventos.

### TrapEvent

Evento que causa daño al jugador.

### RewardEvent

Evento que otorga recompensas al jugador.

---

## Objectives

### Objective

Determina si el objetivo principal de la aventura fue completado.

---

## Utilities

### FileManager

Gestiona la creación, validación y carga de archivos.

### Logger

Registra los acontecimientos importantes de la aventura.

### ReportGenerator

Genera el reporte final del sistema.

---

## Exceptions

### GameException

Clase base para las excepciones del sistema.

### FileException

Errores relacionados con archivos.

### InvalidDataException

Errores relacionados con datos inválidos.

### SimulationException

Errores producidos durante la simulación.

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
```

---

# Manejo de Archivos y Rutas

El sistema utiliza rutas relativas mediante la biblioteca estándar `std::filesystem`.

Gracias a esta estrategia, la aplicación puede ejecutarse en diferentes computadoras sin necesidad de modificar rutas absolutas dentro del código fuente.

Durante la ejecución se crean automáticamente las carpetas:

```text
data/
output/
```

La carpeta `data` almacena los archivos de entrada:

```text
rooms.txt
connections.txt
items.txt
enemies.txt
```

La carpeta `output` almacena los archivos generados por el sistema:

```text
log.txt
final_report.txt
```

---

# Archivos de Entrada

## rooms.txt

Define las habitaciones del mundo.

```text
1|Entrance|Inicio de la mazmorra
2|Hallway|Pasillo oscuro
3|Treasure Room|Sala del tesoro
4|Dragon Lair|Guarida del dragon
```

## connections.txt

Define las conexiones entre habitaciones.

```text
1|2
2|3
3|4
```

## items.txt

Define los objetos presentes en las habitaciones.

```text
1|Potion|Small Potion|25|30
3|Treasure|Ancient Crown|150|Legendary
3|Key|Golden Key|50|4
```

## enemies.txt

Define los enemigos presentes en el mundo.

```text
4|Drogon|Dragon|45|25|150
```

---

# Archivos Generados

## log.txt

Contiene la bitácora completa de la aventura.

## final_report.txt

Contiene el reporte final generado automáticamente al finalizar la simulación.

---

# Tecnologías Utilizadas

- C++20
- STL (Standard Template Library)
- std::filesystem
- std::unique_ptr
- CMake
- CLion

---

# Conceptos del Curso Aplicados

## Herencia

- Character → Player
- Character → Enemy
- Item → Potion
- Item → Key
- Item → Treasure
- GameEvent → TrapEvent
- GameEvent → RewardEvent

## Polimorfismo

Se utiliza mediante clases abstractas para representar personajes, objetos y eventos.

## Encapsulamiento

Los atributos internos de las clases permanecen protegidos mediante métodos públicos.

## Composición

- World contiene habitaciones.
- Room contiene objetos y enemigos.
- SimulationEngine contiene eventos y objetivos.
- AdventureEngine coordina los componentes principales del sistema.

## Manejo de Excepciones

Se utilizan excepciones personalizadas para controlar errores de forma segura.

## Manejo de Archivos

El sistema carga información desde archivos de texto y genera archivos de salida automáticamente.

## Smart Pointers

Se utiliza `std::unique_ptr` para administrar memoria dinámica y evitar fugas de memoria.

---

# Compilación y Ejecución

## Requisitos

- C++20
- CMake
- Compilador compatible con C++20

## Ejecución

1. Clonar o descargar el proyecto.
2. Abrir el proyecto en CLion.
3. Compilar el proyecto.
4. Ejecutar la aplicación.
5. El sistema generará automáticamente las carpetas y archivos necesarios.
6. Al finalizar se generarán la bitácora y el reporte final.

---

# Resultados Obtenidos

El sistema permite:

- Construir el mundo desde archivos.
- Explorar habitaciones.
- Administrar inventarios.
- Ejecutar eventos.
- Combatir enemigos.
- Cumplir objetivos.
- Generar bitácoras.
- Generar reportes finales.

La implementación demuestra la integración práctica de los conceptos estudiados durante el curso.

---

# Autores

**Chris Martínez Sánchez**  
Cédula: 119550022

**Jimena Valencia Montero**  
Cédula: 402710618

Universidad Nacional de Costa Rica  
Escuela de Informática  
EIF204 - Programación II
