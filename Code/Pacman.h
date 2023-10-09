/*?/fndef PACMAN_H
#define PACMAN_H

#include <utility>

enum class Direction { LEFT, UP, RIGHT, DOWN };

class Pacman {
public:
    Pacman();
    void move(Direction dir);

    // Getter functions
    int getLives() const;
    int getScore() const;
    std::pair<int, int> getPosition() const;
    Direction getDirection() const;

    // Setter functions
    void setLives(int lives);
    void setScore(int score);
    void setPosition(int x, int y);
    void setDirection(Direction dir);

private:
    int lives;
    int score;
    std::pair<int, int> position;
    Direction direction;
    
};

#endif // PACMAN_H
