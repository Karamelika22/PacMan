#include "Board.h"
#include "Pacman.h"
#include "Ghost.h"
#include <iostream>
#include <windows.h>

int life = 5;

int main() {
    HWND s = GetConsoleWindow();
    MoveWindow(s, 300, 200, 250, 450, true);
    hideCursor();
    setup();
    while (life > 0) {
        display();
        input();
        movements();
    }

    return 0;
}