#include "Ghost.h"

Ghost::Ghost(GhostType type) {
    
    this->type = type;

  
    switch (type) {
    case GhostType::RED:
        
        xPosition = 10; 
        yPosition = 10; 
        direction = Direction::LEFT; 
        
        break;

    case GhostType::BLUE:
       
        xPosition = 6; 
        yPosition = 6; 
        direction = Direction::UP; 
        
        break;

        
     default:
        break;

       
      
    }
}

void Ghost::move() {
    
    switch (direction) {
    case Direction::LEFT:
        xPosition--;
        break;

    case Direction::UP:
        yPosition--;
        break;

    case Direction::RIGHT:
        xPosition++;
        break;

    case Direction::DOWN:
        yPosition++;
        break;

       

    default:
        break;
    }
}

