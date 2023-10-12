#pragma once

class Enemy {
public:
    int x;
    int y;
    int dir;
    int delay;
    int count_delay;

    void drwa();
    void move();
    bool collision(int fx, int fy);
};