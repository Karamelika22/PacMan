/*/
#pragma once
#ifndef FRUITS_H
#define FRUITS_H

enum class FruitType { CHERRY, STRAWBERRY, APPLE, ORANGE, PEAR };

class Fruit {
public:
    Fruit(FruitType type, int x, int y);

    FruitType getType() const;
    int getX() const;
    int getY() const;
    bool isCollected() const;
    void setCollected(bool collected);

    // Add more member functions and variables as needed

private:
    FruitType type;
    int xPosition;
    int yPosition;
    bool collected;
    // Add other member variables specific to the Fruit class
};

#endif // FRUITS_H

