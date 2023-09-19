#include "Fruits.h"

Fruit::Fruit(FruitType type, int x, int y)
    : type(type), xPosition(x), yPosition(y), collected(false) {
    
}

FruitType Fruit::getType() const {
    return type;
}

int Fruit::getX() const {
    return xPosition;
}

int Fruit::getY() const {
    return yPosition;
}

bool Fruit::isCollected() const {
    return collected;
}

void Fruit::setCollected(bool collected) {
    this->collected = collected;
}



