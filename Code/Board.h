/*/
#pragma once
#ifndef BOARD_H
#define BOARD_H

#include "Pacman.h"
#include "Ghost.h"
#include "Fruits.h"

class Board {
public:
    Board();
    void initialize();
    void display();
    void update();
    bool isGameOver() const;
};

#endif // BOARD_H

