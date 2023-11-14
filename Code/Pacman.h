/**
 * @file Pacman.h
 * @brief Header file for the Pacman class.
 * @details Contains declarations for the Pacman class, representing the player's character.
 *
 * @author Popovici Anastasia
 * @date 2023
 */

#pragma once

 /**
  * @brief Class representing the player's character, Pacman.
  */
class Pacman {
public:
    int x; ///< x-coordinate of Pacman.
    int y; ///< y-coordinate of Pacman.
    char dir; ///< Direction of Pacman.
    int delay; ///< Delay before Pacman moves.
    int count_delay; ///< Counter for the delay.

    /**
     * @brief Draws Pacman on the game board.
     */
    void draw();

    /**
     * @brief Moves Pacman on the game board.
     */
    void move();

    /**
     * @brief Checks for collision with a specified point.
     * @param fx x-coordinate of the point to check.
     * @param fy y-coordinate of the point to check.
     * @return True if there is a collision, false otherwise.
     */
    bool collision(int fx, int fy);

    /**
     * @brief Handles the death of Pacman.
     */
    void dead();

    /**
     * @brief Handles Pacman eating an object.
     */
    void eat();
};
