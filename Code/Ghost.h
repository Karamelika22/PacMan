/*/
#pragma once
#ifndef GHOST_H
#define GHOST_H

enum class GhostType { RED, BLUE, PINK, ORANGE };

class Ghost {
public:
    Ghost(GhostType type);
    void move();

    GhostType getType() const;
    int getX() const;
    int getY() const;

    void setPosition(int x, int y);
    void setDirection(Direction dir);


private:
    GhostType type;
    int xPosition;
    int yPosition;
    Direction direction;

};

#endif // GHOST_H
/*/

#ifndef GHOST_H
#define GHOST_H

//extern const int screenWidth;
//extern const int screenHeight;

class Ghost {
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




#endif // GHOST_H