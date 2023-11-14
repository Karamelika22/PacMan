/**
 * @file Enemy.h
 * @brief Header file for the Enemy class.
 * @details Contains declarations for the Enemy class, representing in-game enemies.
 *
 * @author Popovici Anastasia
 * @date 2023
 */

#pragma once

 /**
  * @brief Class representing an enemy in the game.
  */
class Enemy {
public:
    int x; ///< x-coordinate of the enemy.
    int y; ///< y-coordinate of the enemy.
    int dir; ///< Direction of the enemy.
    int delay; ///< Delay before the enemy moves.
    int count_delay; ///< Counter for the delay.

    /**
     * @brief Default constructor for the Enemy class.
     */
    Enemy();

    /**
     * @brief Parameterized constructor for the Enemy class.
     * @param x Initial x-coordinate.
     * @param y Initial y-coordinate.
     * @param dir Initial direction.
     * @param delay Delay before movement.
     * @param count_delay Counter for delay.
     */
    Enemy(int x, int y, int dir, int delay, int count_delay);

    /**
     * @brief Copy constructor for the Enemy class.
     * @param other The enemy object to be copied.
     */
    Enemy(const Enemy& other);

    /**
     * @brief Overloaded equality operator for comparing two Enemy objects.
     * @param other The enemy object to compare with.
     * @return True if the objects are equal, false otherwise.
     */
    bool operator==(const Enemy& other) const;

    /**
     * @brief Draws the enemy on the game board.
     */
    void draw();

    /**
     * @brief Moves the enemy on the game board.
     */
    void move();

    /**
     * @brief Checks for collision with a specified point.
     * @param fx x-coordinate of the point to check.
     * @param fy y-coordinate of the point to check.
     * @return True if there is a collision, false otherwise.
     */
    bool collision(int fx, int fy);
};
