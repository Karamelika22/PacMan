#include "Enemy.h"
#include "Board.h"
#include <cstdlib>

void Enemy::drwa() {
    map[y][x] = 5;
}

void Enemy::move() {
    if (count_delay == delay) {
        if (dir == 0 && !collision(x, y - 1)) y--;
        if (dir == 1 && !collision(x, y + 1)) y++;
        if (dir == 2 && !collision(x - 1, y)) x--;
        if (dir == 2 && !collision(x + 1, y)) x++;
        count_delay = 0;
        dir = rand() % 4;
    }
    count_delay++;
}

bool Enemy::collision(int fx, int fy) {
    if (map[fy][fx] == 9) return true;
    return false;
}