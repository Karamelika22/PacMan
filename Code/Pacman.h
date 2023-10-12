#pragma once

class Pacman {
public:
    int x;
    int y;
    char dir;
    int delay;
    int count_delay;

    void draw();
    void move();
    bool collision(int fx, int fy);
    void dead();
    void eat();
};