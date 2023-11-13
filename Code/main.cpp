#include "Pacman.h"
#include "Enemy.h"
#include "Board.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <algorithm>

Pacman pacman;
Enemy enemy[7];

void setup() {

    srand(time(NULL));
    pacman.x = 10;
    pacman.y = 15;
    pacman.dir = 'S';
    pacman.delay = 2;

    enemy[0] = Enemy(9, 9, 0, 3, 0);
    enemy[1] = Enemy(10, 9, 0, 5, 0);
    enemy[2] = Enemy(11, 9, 0, 5, 0);
    enemy[3] = Enemy(2, 1, 0, 5, 0);
    enemy[4] = Enemy(18, 1, 0, 5, 0);
    enemy[5] = Enemy(2, 19, 0, 5, 0);
    enemy[6] = Enemy(18, 19, 0, 5, 0);
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
    std::for_each(std::begin(enemy), std::end(enemy), [](Enemy& e) { e.move(); });
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