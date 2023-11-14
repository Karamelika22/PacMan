/**
 * @file Board.h
 * @brief Header file for the Board class.
 * @details Contains declarations for the game board related functions and variables.
 *
 * @author Anastasia Popovici
 * @date 2023
 */

#pragma once

#include <vector>
#include <string>

extern const int screenHeight; ///< Constant representing the screen height.
extern const int screenWidth;  ///< Constant representing the screen width.
extern std::vector<std::string> map;   ///< Vector of strings representing the game map.
extern std::vector<std::string> stage; ///< Vector of strings representing the game stage.
extern int life; ///< Integer representing the player's life.

/**
 * @brief Sets up the layout of the game board.
 */
void layout();

/**
 * @brief Displays the current state of the game board.
 */
void display();

/**
 * @brief Moves the cursor to the specified coordinates on the console.
 * @param x The x-coordinate.
 * @param y The y-coordinate.
 */
void gotoxy(int x, int y);

/**
 * @brief Hides the cursor on the console.
 */
void hideCursor();

/**
 * @brief Initializes the game map and other variables.
 */
void initializeMap();
