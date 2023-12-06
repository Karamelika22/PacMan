#include "Pacman.h"
#include "Board.h"

void Pacman::draw() {
    if (dir == 'U') map[y][x] = 'V';
    else if (dir == 'D') map[y][x] = '^';
    else if (dir == 'L') map[y][x] = '>';
    else if (dir == 'R' || dir == 'S') map[y][x] = '<';

    if (dir != 'S' && dir != 'R') {
        if (dir == 'U') map[y + 1][x] = ' ';
        else if (dir == 'D') map[y - 1][x] = ' ';
        else if (dir == 'L') map[y][x + 1] = ' ';
    }
    else if (dir == 'R') {
        map[y][x - 1] = ' ';
    }
}

void Pacman::move() {
    dead();
    if (count_delay == delay) {
        if (dir == 'U' && !collision(x, y - 1)) y--;
        if (dir == 'D' && !collision(x, y + 1)) y++;
        if (dir == 'L' && !collision(x - 1, y)) x--;
        if (dir == 'R' && !collision(x + 1, y)) x++;
        count_delay = 0;
    }
    count_delay++;
    eat();
}

bool Pacman::collision(int fx, int fy) {
    if (map[fy][fx] == '#') return true;
    return false;
}

void Pacman::dead() {
    if (map[y][x] == 'E') {
        dir = 'S';
        x = 10;
        y = 15;
        life--;
    }
}

void Pacman::eat() {
    if (map[y][x] == '.') {
        stage[y][x] = ' ';
    }
}