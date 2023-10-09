
#include "Ghost.h"
#include "Board.h"
#include <cstdlib>



void Ghost::drwa() {
    map[y][x] = 5;
}

void Ghost::move() {
    dir = rand() % 4;
    if (dir == 0 && !collision(x, y - 1)) y--;
    if (dir == 1 && !collision(x, y + 1)) y++;
    if (dir == 2 && !collision(x - 1, y)) x--;
    if (dir == 3 && !collision(x + 1, y)) x++;
}

bool Ghost::collision(int fx, int fy) {
    if (map[fy][fx] == 9)return true;
    return false;
}


