This project has been created as part of the 42 curriculum by nmeunier.

## Overview

**so_long** is a simple 2D game built with the MLX graphics library. The goal is to collect all items on the map and reach the exit to win the game.

## Features

- 2D tile-based game world
- Player movement in 4 directions (WASD)
- Collectible items to gather
- Exit tile that becomes accessible only after collecting all items
- Move counter that tracks player's movements
- Graphics-based interface using MLX library

## Controls

- **W** - Move up
- **A** - Move left
- **S** - Move down
- **D** - Move right
- **ESC** - Quit the game

## Game Rules

1. Navigate the map using WASD keys
2. Collect all collectible items (marked with 'C' on the map)
3. The exit ('E') is blocked until all collectibles are gathered
4. Once all items are collected, move to the exit to win
5. The game displays the number of moves made

## Map Format

Maps are defined in `.ber` files with the following characters:

- `1` - Wall (impassable)
- `0` - Empty space
- `P` - Player starting position
- `C` - Collectible item
- `E` - Exit

## Building the Project

```bash
make
```

## Running the Game

```bash
./so_long maps/map_name.ber
```

## Requirements

- GCC compiler with `-Wall -Wextra -Werror` flags
- X11 graphics library
- MLX graphics library (included in project)

## Project Structure

- `src/` - Source files containing game logic
- `images/` - Game sprites (XPM format)
- `maps/` - Map files for testing
- `mlx/` - MLX graphics library
- `libft/` - Custom C library functions
- `gnl/` - Get Next Line function
- `includes/` - Header files

## Cleanup

```bash
make fclean    # Remove all build files and executable
make clean     # Remove only object files
```