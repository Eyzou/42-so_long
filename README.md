
# so_long by Eyou

## Overview

`so_long` is a simple 2D game project developed as part of the 42 coding school curriculum. 
The objective of the game is to navigate through a maze, collect all the collectibles, and reach the exit without getting caught by enemies.

## Features

- **2D graphics rendering** using the MiniLibX library.
- **Player movement and collision detection**.
- **Collectibles** the player neesd to collect all the carrots!!
- **Basic enemy random move** - using the rand() function.
- **Win and lose conditions**. - Help the nice witch to catch her kitty cat!!

## Getting Started

### Prerequisites

To run the `so_long` project, you need the following:

- A Unix-like operating system (Linux or macOS). I have added both options in the Makefile - feel free to uncomment.
- The MiniLibX library installed on your system.
- A C compiler (gcc or clang).

### Installation

1. **Clone the repository:**

   ```bash
   git clone https://github.com/Eyzou/so_long.git
   cd so_long
   ```

2. **Compile the project:**

without bonus
   ```bash
   make 
   ```
with bonus

 ```bash
   make  bonus
   ```

### Running the Game

To start the game, run the following command:

```bash
./so_long maps/map.ber
```

Replace `maps/map.ber` with the path to your map file.

## Controls

- **W**: Move up
- **A**: Move left
- **S**: Move down
- **D**: Move right
- **ESC**: Exit the game

## Map Format

The game maps are defined in `.ber` files and should follow this format:

- **`1`**: Wall
- **`0`**: Empty space
- **`P`**: Player start position
- **`E`**: Exit
- **`C`**: Collectible
- **`M`**: Enemy

Example map:

```
111111
1P0C1E
111111
```

## Author

This project was developed by **[EYZOU LA PTITE GOAT]** as part of the 42 curriculum.

---
