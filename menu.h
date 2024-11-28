#pragma once

#include <iostream>
#include "game.h"
#include "instructions.h"

class Menu {
    Game game;
    Instructions instructions;
    // Enum for user choices
    enum MenuChoice {
        START = 1,
        INSTRUCTIONS = 8,
        EXIT = 9
    };
public:
    void run_main(); // Main menu loop
    void endGame();
};

