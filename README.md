# Ecole42-So_long

A simple 2D game made in C using the Minilibx library for graphics.

## Overview

Ecole42-So_long is a 2D game project developed for Ecole 42. The game is built using the Minilibx, a simple graphic library developed internally at Ecole 42.

In this game, the player controls a character who must collect all the coins on a given level while avoiding enemies. The game is set in a limited space, and the player must navigate through the level by moving up, down, left, and right. The game ends when the player either collects all the coins or collides with an enemy.

The project is implemented in C, and makes use of various data structures and algorithms, including dynamic memory allocation, linked lists, and breadth-first search. It also includes some basic error handling and parsing of command-line arguments.

The Minilibx library provides basic graphics capabilities for drawing and rendering images, as well as keyboard input handling. It also provides access to low-level X Window System and OpenGL functions.

Overall, Ecole42-So_long is a fun and challenging project that showcases the capabilities of the Minilibx library and provides an introduction to game development concepts.

## Installation

Clone the repository: `https://github.com/Feanor1021/Ecole42-So_long.git`

## Usage

To run the game, you need to have the Minilibx library installed on your system. You can install it by following the instructions provided in the [Minilibx repository](https://github.com/42Paris/minilibx-linux). Once you have installed the library, you can compile the game using the Makefile:

You have to compile your project with this flags.

    -framework OpenGL -framework AppKit mlx/libmlx.a 

```bash
make
./so_long [map_file]
```

## Controls

* Move up: `W` or `UP arrow`
* Move down: `S` or `DOWN arrow`
* Move left: `A` or `LEFT arrow`
* Move right: `D` or `RIGHT arrow`
* Exit the game: `ESC`

## Map format

The game reads maps from a text file with a `.ber` extension. Maps must be rectangular and have at least one exit, one player and some collectible coins. Walls are represented by the character `1`, floors by `0`, the player character by `P`, the exit by `E`, enemy by `F`,and coins by `C`.

Examples:

111111<br />
1E0101<br />
101001<br />
1C0001<br />
111111<br />

Or

111111<br />
1E0101<br />
101C01<br />
10F001<br />
111111<br />

For bonus map

## Credits

This project was completed as part of the curriculum for Ecole 42, a project-based programming school. The game was programmed by me (Feanor1021) using the Minilibx library for graphics.
