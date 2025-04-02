#ifndef SNAKE_INPUT_H
#define SNAKE_INPUT_H

#include <windows.h> // For Windows API functions

// Function to check if a key is pressed
bool IsKeyPressed(int key) {
    return (GetAsyncKeyState(key) & 0x8000) != 0;
}

// Function to get the direction based on WASD keys
char GetDirection() {
    if (IsKeyPressed('W') || IsKeyPressed(VK_UP)) {
        return 'W';
    } else if (IsKeyPressed('A') || IsKeyPressed(VK_LEFT)) {
        return 'A'; 
    } else if (IsKeyPressed('S') || IsKeyPressed(VK_DOWN)) {
        return 'S';
    } else if (IsKeyPressed('D') || IsKeyPressed(VK_RIGHT)) {
        return 'D';
    }
    return '\0'; // No key pressed
}

#endif -