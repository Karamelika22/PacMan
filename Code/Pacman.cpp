#include "Pacman.h"

Pacman::Pacman()
    : lives(3), score(0), position(std::make_pair(0, 0)), direction(Direction::RIGHT) {
   
}
