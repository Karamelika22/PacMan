#include "Enemy.h"
#include "Board.h"
#include <cstdlib>
#include <iostream>

Enemy::Enemy() {
    x = 0;
    y = 0;
    dir = 0;
    delay = 1;
    count_delay = 0;
}

Enemy::Enemy(int startX, int startY, int startDir, int startDelay, int startCountDelay) {
    x = startX;
    y = startY;
    dir = startDir;
    delay = startDelay;
    count_delay = startCountDelay;
}

Enemy::Enemy(const Enemy& other) {
    x = other.x;
    y = other.y;
    dir = other.dir;
    delay = other.delay;
    count_delay = other.count_delay;
}

bool Enemy::operator==(const Enemy& other) const {
    return (x == other.x && y == other.y && dir == other.dir && delay == other.delay && count_delay == other.count_delay);
}

std::istream& operator>>(std::istream& is, Enemy& enemy) {
    is >> enemy.x >> enemy.y >> enemy.dir >> enemy.delay >> enemy.count_delay;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Enemy& enemy) {
    os << "x: " << enemy.x << ", y: " << enemy.y << ", dir: " << enemy.dir << ", delay: " << enemy.delay << ", count_delay: " << enemy.count_delay;
    return os;
}

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