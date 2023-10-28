#pragma once

class Enemy {
public:
    int x;
    int y;
    int dir;
    int delay;
    int count_delay;

    Enemy();
    Enemy(int, int, int, int, int);
    Enemy(const Enemy& other);
    bool operator==(const Enemy& other) const;

    void drwa();
    void move();
    bool collision(int fx, int fy);
};