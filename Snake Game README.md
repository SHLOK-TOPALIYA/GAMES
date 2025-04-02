Project1-Snake_game
•Snake Game using C++

A fun and simple Snake Game built in C++ using Object-Oriented Programming (OOP) principles. Navigate the snake, eat food, and avoid crashing into the borders!

#️⃣Features:

Tried to cover all the necessary points mentioned in the Project 1 Document.
Classic snake gameplay on a 25x50 grid
Modular design for easy readability and modifications
Real-time user input handling
As the snake eats the food (represented using symbol "*" )the lenght increases
Displays final score when the snake crashes
Works on multiple operating systems (no conio.h required!) (made own header file to read input)
#️⃣Controls:

Key: Move Snake (Up-"W", Down-"S", Left-"A", Right-"D")
#️⃣About SnakeInput.h:

•The SnakeInput.h file handles user input for controlling the snake in the game. It uses Windows-specific functions (GetAsyncKeyState) to detect key presses without blocking program execution.

•Detects WASD or arrow keys for movement.

•Uses GetAsyncKeyState() for real-time key detection.

•Returns \0 when no key is pressed, preventing unnecessary direction changes.

#️⃣Limitations:

-This Snake Game is designed to work on Windows OS. It utilizes Windows-specific libraries such as windows.h for console manipulation (SetConsoleCursorPosition, Sleep, and system("cls")).

Compatibility with other operating systems like Linux or macOS is not guaranteed without modifications.

-Designed for terminal play, no GUI support.
