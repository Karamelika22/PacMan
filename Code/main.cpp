#include "Pacman.h"
#include "Enemy.h"
#include "Board.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>

Pacman pacman;
Enemy enemy[7];

void setup() {

    srand(time(NULL));
    pacman.x = 10;
    pacman.y = 15;
    pacman.dir = 'S';
    pacman.delay = 2;


    enemy[0].x = 9;
    enemy[0].y = 9;
    enemy[0].delay = 3;

    enemy[1].x = 10;
    enemy[1].y = 9;
    enemy[1].delay = 5;

    enemy[2].x = 11;
    enemy[2].y = 9;
    enemy[2].delay = 5;

    enemy[3].x = 2;
    enemy[3].y = 1;
    enemy[3].delay = 5;

    enemy[4].x = 18;
    enemy[4].y = 1;
    enemy[4].delay = 5;

    enemy[5].x = 2;
    enemy[5].y = 19;
    enemy[5].delay = 5;

    enemy[6].x = 18;
    enemy[6].y = 19;
    enemy[6].delay = 5;
}
void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void hideCursor() {
    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize = 100;
    cursor.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void input() {
    if (kbhit()) {
        switch (getch()) {
        case 80:
            if (!pacman.collision(pacman.x, pacman.y + 1)) pacman.dir = 'D';
            break;
        case 72:
            if (!pacman.collision(pacman.x, pacman.y - 1))pacman.dir = 'U';
            break;
        case 75:
            if (!pacman.collision(pacman.x - 1, pacman.y)) pacman.dir = 'L';
            break;
        case 77:
            if (!pacman.collision(pacman.x + 1, pacman.y)) pacman.dir = 'R';
            break;
        }
    }
}

void movements() {
    pacman.move();
    for (int i = 0; i < 7; i++) enemy[i].move();
}

int main() {
    HWND s = GetConsoleWindow();
    MoveWindow(s, 300, 200, 250, 450, true);
    hideCursor();
    initializeMap();
    setup();
    layout();
    while (life > 0) {
        display();
        input();
        movements();
    }

    std::cout << "Game Over. Press any key to exit..." << std::endl;
    getch();
    Sleep(2000);

    return 0;
}