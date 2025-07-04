# CONSOLE GAME ENGINE

A simple yet powerful console-based game engine written in C++
Supports game creation, player movement, item pickup, monster AI, and turn-based combat

-------------------------------------------------------------------------

## OVERVIEW

This is a *fully functional console-based game engine* that allows users to:

 - Create maps using `.vxe` file extension and format
 - Place entities like monsters, items and traps
 - Implement player movement and interaction
 - Add inventory and combat systems

All built entirely with C++ without using any external libraries.

-------------------------------------------------------------------------

## FEATURES

| Feature | Description |
|---------|-------------|
| **Map System** | Loads ASCII maps from `.vxe` files |
| **Game Creation** | Users can create their own games into a `.vxe` file |
| **Player Movement** | WASD keys, bounds checking, wall collision |
| **Monster A.I.** | Enemies move towards the player intelligently |
| **Combat System** | Turn-based battle with HP tracking |
| **Item Pickup** | Collect items and track them in inventory |
| **Inventory System** | Shows collected items (e.g. "Bread x2", "Sword x1") |
| **Collision Detection** | Detects when the player hits walls, items, enemies, or traps |

-------------------------------------------------------------------------

## TECHNOLOGIES USED

 - **C++17**
 - **Standard Template Library (STL)**: `vector`, `map`, `string`, `fstream`, `iostream`
 - **Object-Oriented Programming (OOP)**: Structured around `Designer`, `Compiler`, `Game`, `Player`, `Entity`, `Item`, and `Trap` classes
 - **FileIO**: Load maps from a `.vxe` file

-------------------------------------------------------------------------

## GETTING STARTED

### PREREQUISITES

 - **C++ Compiler**: `g++`, `clang++`, `MSVC`
 - **Terminal** or command-line interface access

### BUILD INSTRUCTIONS

To compile and run the app from project root:

`g++ src/main.cpp src/Designer.cpp src/Compiler.cpp src/Game.cpp src/Player.cpp src/Entity.cpp src/Item.cpp src/Trap.cpp -o engine`
`./engine`
