#include <bits/stdc++.h>
#include <windows.h>
#include "SnakeInput.h"

using namespace std;

#define MAX_LEN 1000

// Directions
const char U = 'W'; // Up
const char D = 'S'; // Down
const char L = 'A'; // Left
const char R = 'D'; // Right

const int w = 50, h = 25; // Fixed grid size

// Structure to represent a point (x, y)
struct P
{
    int x, y;
    P() {}
    P(int x, int y) : x(x), y(y) {}
};

// Snake class
class Snake
{
    int len;  // Length of the snake
    char dir; // Current direction
public:
    P body[MAX_LEN]; // Body segments

    Snake(int x, int y)
    {
        len = 3;
        body[0] = P(x, y);
        body[1] = P(x - 1, y);
        body[2] = P(x - 2, y);
        dir = R;
    }

    int getLen() { return len; }

    void changeDir(char newDir)
    {
        if ((newDir == U && dir != D) || (newDir == D && dir != U) ||
            (newDir == L && dir != R) || (newDir == R && dir != L))
        {
            dir = newDir;
        }
    }

    bool move(P f)
    {
        for (int i = len - 1; i > 0; i--)
            body[i] = body[i - 1];

        switch (dir)
        {
        case U:
            body[0].y--;
            break;
        case D:
            body[0].y++;
            break;
        case R:
            body[0].x++;
            break;
        case L:
            body[0].x--;
            break;
        }

        // Check if snake hits the border
        if (body[0].x <= 0 || body[0].x >= w - 1 || body[0].y <= 0 || body[0].y >= h - 1)
        {
            return false;
        }

        // Check if snake collides with itself
        for (int i = 1; i < len; i++)
        {
            if (body[0].x == body[i].x && body[0].y == body[i].y)
                return false;
        }

        // Check if food is eaten
        if (f.x == body[0].x && f.y == body[0].y)
        {
            body[len] = P(body[len - 1].x, body[len - 1].y);
            len++;
        }

        return true;
    }
};

// Board class
class Board
{
    Snake *s;
    const char BODY = 'O';
    P f;
    const char FOOD = '*';
    int score;

public:
    Board()
    {
        appearFood();
        s = new Snake(w / 2, h / 2);
        score = 0;
    }

    ~Board() { delete s; }

    int getScore() { return score; }

    void appearFood()
    {
        f = P(rand() % (w - 2) + 1, rand() % (h - 2) + 1);
    }

    void displayScore()
    {
        gotoxy(w + 5, 2);
        cout << "Score: " << score;
    }

    void gotoxy(int x, int y)
    {
        COORD coord = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

    void draw()
    {
        system("cls");

        // Draw border
        for (int i = 0; i < w; i++)
        {
            gotoxy(i, 0);
            cout << "_";
            gotoxy(i, h - 1);
            cout << "_";
        }
        for (int i = 0; i < h; i++)
        {
            gotoxy(0, i);
            cout << "|";
            gotoxy(w - 1, i);
            cout << "|";
        }

        // Draw snake
        for (int i = 0; i < s->getLen(); i++)
        {
            gotoxy(s->body[i].x, s->body[i].y);
            cout << BODY;
        }

        // Draw food
        gotoxy(f.x, f.y);
        cout << FOOD;

        displayScore();
    }

    bool update()
    {
        if (!s->move(f))
            return false;
        if (f.x == s->body[0].x && f.y == s->body[0].y)
        {
            score++;
            appearFood();
        }
        return true;
    }

    void getInput()
    {
        char direction = GetDirection();
        if (direction != '\0')
        {
            s->changeDir(direction);
        }
    }
};

int main()
{
    srand(time(0));
    Board *b = new Board();
    
    while (b->update())
    {
        b->getInput();
        b->draw();
        Sleep(120);
    }


    // Display final score when the game ends
    system("cls");
    cout << "\n\n\tGame Over!\n";
    cout << "\tFinal Score: " << b->getScore() << "\n\n";

    delete b;
    return 0;
}