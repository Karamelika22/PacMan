
#ifndef PACMAN_H
#define PACMAN_H

//extern const int screenWidth;
//extern const int screenHeight;

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



#endif // PACMAN_H
