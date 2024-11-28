#pragma once

#include <iostream>
#include <windows.h>
#include "Point.h"      // Handles the point-based logic for positions
#include <conio.h>      // For keyboard input handling
#include "utils.h"      // Utility functions like 'gotoxy' and others
#include "gameConfig.h" // Configuration and key definitions
#include "Board.h"      // Board logic for printing and managing the game state
#include "mario.h"      // Mario-specific logic

class Game {
    // Private member variables
    GameConfig config;
    int score = 0;             // Player's score (if needed later for gameplay)
    bool died = false;         // Flag to indicate if Mario has died
    Mario mario;               // Instance of the Mario character
    Board board;               // The game board representation
    Point pac_reset;           // Reset position for Mario after death


public:
    // Main function to run the game
    void run_game();

    // Check if the player has died (to be implemented)
    void check_if_died();

    // Handle what happens when Mario dies
    void handleDeath();

    // Pause the game and wait for the user to resume
    void pauseGame();

    // Handle keyboard input from the user
    void handleInput(char key);

    // Play one life, handling the gameplay loop until Mario dies or pauses
    void playSingleLife();

    // Initialize the game board and data
    void initializeGame();
};