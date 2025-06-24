# CONSOLE GAME ENGINE

A simple yet powerful console-based game engine written in C++
Supports player movement, item pickup, monster AI, and turn-based combat

-------------------------------------------------------------------------

## OVERVIEW

This is a *fully functional console-based game engine* that allows developers to:

 - Create maps using `.txt` files
 - Place entities like monsters and items
 - Implement player movement and interaction
 - Add inventory and combat systems

All built entirely with C++ without using any external libraries.

-------------------------------------------------------------------------

## FEATURES

| Feature | Description |
|---------|-------------|
| **Map System** | Loads ASCII maps from `.txt` files |
| **Player Movement** | WASD keys, bounds checking, wall collision |
| **Monster A.I.** | Enemies move towards the player intelligently |
| **Combat System** | Turn-based battle with HP tracking |
| **Item Pickup** | Collect items and track them in inventory |
| **Inventory System** | Shows collected items (e.g. "Bread x2", "Sword x1") |
| **Collision Detection** | Detects when the player hits walls, items, or enemies |

-------------------------------------------------------------------------

## TECHNOLOGIES USED

 - **C++17**
 - **Standard Template Library (STL)**: `map`, `vector`, `string`, `fstream`, `iostream`
 - **Object-Oriented Programming (OOP)**: Structured around `Game`, `Player`, `Entity`, `Item` classes
 - **FileIO**: Load maps from a `.txt` file

-------------------------------------------------------------------------

## GETTING STARTED

### PREREQUISITES

 - **C++ Compiler**: `g++`, `clang++`, `MSVC`
 - **Terminal** or command-line interface access

### BUILD INSTRUCTIONS

To compile and run the app from project root:

`g++ src/main.cpp include/Game.cpp include/Player.cpp include/Entity.cpp include/Item.cpp -o game`
`./game`
