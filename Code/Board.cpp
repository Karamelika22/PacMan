#include "Board.h"
#include "Pacman.h"
#include "Ghost.h"
#include "Fruit.h"

Board::Board() {
    
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            gameBoard[i][j] = ' ';
        }
    }
}

void Board::initialize() {
    
    pacman = Pacman();
    pacman.setPosition(1, 1); 
    pacman.setLives(3);      
    pacman.setScore(0);       

    
    redGhost = Ghost(GhostType::RED);
    redGhost.setPosition(5, 5); 


    cherry = Fruit(FruitType::CHERRY, 2, 2);       
    strawberry = Fruit(FruitType::STRAWBERRY, 7, 7); 

    
}

void Board::display() {
   
}

void Board::update() {
    
}

bool Board::isGameOver() const {
    .
    return pacman.getLives() <= 0; 
}
