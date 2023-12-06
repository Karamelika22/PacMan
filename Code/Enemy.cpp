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

void Enemy::draw() {


    map[y][x] = 'E';
}

void Enemy::move() {
    if (count_delay == delay) {
        // 
        map[y][x] = ' ';

        // 
        int new_x = x;
        int new_y = y;

        if (dir == 0 && !collision(x, y - 1)) new_y--;
        else if (dir == 1 && !collision(x, y + 1)) new_y++;
        else if (dir == 2 && !collision(x - 1, y)) new_x--;
        else if (dir == 3 && !collision(x + 1, y)) new_x++;

        // 
        if (!collision(new_x, new_y)) {
            x = new_x;
            y = new_y;
        }

        count_delay = 0;
        dir = rand() % 4;
    }

    count_delay++;
}

bool Enemy::collision(int fx, int fy) {
    if (map[fy][fx] == '#') return true;
    return false;
}