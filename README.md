# Proyecto II - Simulación de Mazmorra

## Universidad Nacional de Costa Rica

### Facultad de Ciencias Exactas y Naturales

### Escuela de Informática

### EIF204 - Programación II

**Profesor:** Luis Elías Mora Montero

**Integrantes:**

* Chris Martínez Sánchez — 119550022
* Jimena Valencia Montero — 402710618

---

# Descripción General

El presente proyecto consiste en el desarrollo de una simulación de aventura en una mazmorra utilizando los principios de Programación Orientada a Objetos en C++.

La aplicación permite cargar información desde archivos de texto, administrar habitaciones, personajes, enemigos, objetos y eventos especiales, ejecutando una simulación completa de exploración y combate. Adicionalmente, el sistema genera automáticamente una bitácora de eventos y un reporte final de la aventura.

Durante el desarrollo se aplicaron conceptos fundamentales del curso tales como herencia, polimorfismo, encapsulamiento, abstracción, manejo de excepciones, composición, modularización y administración de memoria mediante punteros inteligentes.

---

# Objetivos del Proyecto

## Objetivo General

Desarrollar una aplicación orientada a objetos que permita simular una aventura dentro de una mazmorra, integrando múltiples conceptos estudiados durante el curso de Programación II.

## Objetivos Específicos

* Implementar una arquitectura modular basada en clases.
* Aplicar herencia y polimorfismo para la gestión de personajes, objetos y eventos.
* Utilizar archivos de texto para almacenar y cargar información del sistema.
* Implementar manejo de excepciones personalizadas.
* Generar bitácoras y reportes automáticos.
* Aplicar buenas prácticas de programación y organización del código.

---

# Funcionalidades Implementadas

El sistema incorpora las siguientes funcionalidades:

* Creación automática de archivos de configuración.
* Carga de habitaciones desde archivos.
* Carga de enemigos desde archivos.
* Carga de objetos desde archivos.
* Gestión de inventario.
* Exploración de habitaciones.
* Sistema de combate.
* Eventos especiales durante la aventura.
* Objetivos de misión.
* Registro de eventos mediante bitácora.
* Generación de reporte final.
* Manejo de errores mediante excepciones personalizadas.

---

# Estructura del Proyecto

```text
Proyecto2
│
├── include
│   ├── engine
│   ├── entities
│   ├── events
│   ├── exceptions
│   ├── items
│   ├── objectives
│   ├── utils
│   └── world
│
├── src
│   ├── engine
│   ├── entities
│   ├── events
│   ├── exceptions
│   ├── items
│   ├── objectives
│   ├── utils
│   └── world
│
├── data
│   ├── rooms.txt
│   ├── connections.txt
│   ├── items.txt
│   └── enemies.txt
│
├── output
│   ├── log.txt
│   └── final_report.txt
│
├── main.cpp
├── CMakeLists.txt
└── README.md
```

---

# Diseño del Sistema

## Módulo Engine

### AdventureEngine

Controlador principal de la aplicación. Coordina la carga de datos, ejecución de la simulación y generación de reportes.

### SimulationEngine

Administra la lógica de ejecución de la aventura, incluyendo exploración, eventos y combate.

---

## Módulo World

### World

Representa el mundo de juego y administra habitaciones, jugador y eventos.

### Room

Representa una habitación dentro de la mazmorra.

---

## Módulo Entities

### Character

Clase abstracta base para todos los personajes del sistema.

### Player

Representa al jugador principal.

### Enemy

Representa los enemigos presentes en la aventura.

---

## Módulo Items

### Item

Clase abstracta base para todos los objetos.

### Potion

Objeto que permite recuperar puntos de vida.

### Key

Objeto utilizado para acceder a nuevas áreas.

### Treasure

Objeto que otorga puntos de recompensa.

### Inventory

Administra los objetos obtenidos durante la aventura.

---

## Módulo Events

### GameEvent

Clase abstracta base para eventos del juego.

### TrapEvent

Evento que provoca daño al jugador.

### RewardEvent

Evento que otorga recompensas adicionales.

---

## Módulo Objectives

### Objective

Representa el objetivo principal de la aventura y permite determinar si ha sido completado.

---

## Módulo Utilities

### FileManager

Gestiona la creación, validación y carga de archivos.

### Logger

Registra todos los acontecimientos importantes de la simulación.

### ReportGenerator

Genera el reporte final de la aventura.

---

## Módulo Exceptions

### GameException

Clase base para las excepciones del sistema.

### FileException

Gestiona errores relacionados con archivos.

### InvalidDataException

Gestiona errores asociados a datos inválidos.

### SimulationException

Gestiona errores producidos durante la simulación.

---

# Archivos de Entrada

Los siguientes archivos son creados automáticamente por el sistema en caso de no existir:

## rooms.txt

Contiene la definición de las habitaciones.

## connections.txt

Contiene las conexiones entre habitaciones.

## items.txt

Contiene los objetos disponibles en la aventura.

## enemies.txt

Contiene los enemigos presentes en la aventura.

---

# Archivos Generados

## log.txt

Contiene la bitácora completa de los eventos ocurridos durante la simulación.

## final_report.txt

Contiene el reporte final generado automáticamente al concluir la aventura.

---

# Instrucciones de Ejecución

## Requisitos

* C++20
* CMake
* Compilador compatible con C++20

## Pasos de Ejecución

1. Clonar el repositorio.
2. Abrir el proyecto en CLion o cualquier IDE compatible.
3. Compilar el proyecto.
4. Ejecutar la aplicación.
5. El sistema generará automáticamente las carpetas y archivos necesarios.
6. Al finalizar la ejecución se generarán los archivos de salida correspondientes.

---

# Conceptos Aplicados

Durante el desarrollo del proyecto se aplicaron los siguientes conceptos:

* Programación Orientada a Objetos.
* Herencia.
* Polimorfismo.
* Encapsulamiento.
* Abstracción.
* Composición.
* Manejo de Excepciones.
* Lectura y Escritura de Archivos.
* Punteros Inteligentes (`std::unique_ptr`).
* Modularización del Código.
* Diagramas UML.
* Gestión de Memoria Dinámica.
* Separación de Responsabilidades.

---

# Resultados Obtenidos

El sistema permite ejecutar una simulación completa de aventura dentro de una mazmorra, incluyendo exploración, recolección de objetos, activación de eventos, combate contra enemigos, generación de bitácoras y elaboración de reportes finales.

La implementación demuestra la integración de los principales conceptos estudiados durante el curso, manteniendo una arquitectura modular y escalable.

---

# Autores

**Chris Martínez Sánchez**
Cédula: 119550022

**Jimena Valencia Montero**
Cédula: 402710618

Universidad Nacional de Costa Rica
Escuela de Informática
EIF204 - Programación II
