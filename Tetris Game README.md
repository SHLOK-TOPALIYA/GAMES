# Project 2 Tetris_game


## Tetris Game using C++
A fun and engaging Tetris game built in C++ using Object-Oriented Programming (OOP) principles. Stack the blocks, clear lines, and achieve the highest score!

## Features:
- Implements classic Tetris gameplay on a *10*20 grid*
- Modular design for easy readability and modifications
- Real-time user input handling
- Blocks fall automatically and can be moved left, right, rotated, or dropped
- Line clearing system with increasing difficulty
- Displays final score when the game ends
- Works on Windows OS using `windows.h` for console manipulation

## Controls:
- **Arrow Left (`←`)**: Move block left
- **Arrow Right (`→`)**: Move block right
- **Arrow Down (`↓`)**: Soft drop
- **Arrow Up (`↑`)**: Rotate block
- **Spacebar**: Hard drop
- **ESC**: Quit the game

## Input Handling:
- The game handles user input in real-time using `_kbhit()` and `_getch()` for smooth gameplay.
- Detects arrow keys and spacebar for movement and rotation.
- Ensures non-blocking input to allow seamless piece movement.

## Limitations:
- This Tetris Game is designed to **work on Windows OS**. It utilizes Windows-specific libraries such as *windows.h* for console manipulation (`SetConsoleCursorPosition`, `Sleep`, and `system("cls")`).
- Designed for terminal play, no GUI support.
