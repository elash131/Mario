#include "game.h"


void Game::run_game() {
    ShowConsoleCursor(false); // Hide the console cursor
    initializeGame(); // Initialize the game board and data

    for (int live = config.lives; live > 0; live--) {
        playSingleLife(); // Play one life until the player either dies or pauses
    }
}

// Initialize the game by printing the board and setting up the point array
void Game::initializeGame() {
    board.printArrChar();
    board.insertDataToArrPoint();
}

void Game::playSingleLife() {
    char key;
    while (true) {
        died = false; // Reset the 'died' flag
        check_if_died(); // Check if the player died

        if (_kbhit()) {
            key = _getch();
            handleInput(key); // Handle keyboard input
            if (died) {
                handleDeath(); // Handle player death
                break;
            }
        }
        mario.fall(board);
        // Automatically move Mario in the current direction
        if (mario.getDirX() != 0 || mario.getDirY() != 0) {
            mario.move(board, key);
        }
        Sleep(150); // Delay to control game speed
    }
}

// Handle keyboard input from the player
void Game::handleInput(char key) {

    if (static_cast<GameConfig::eKeys>(key) == GameConfig::eKeys::ESC) {
        pauseGame(); // Pause the game if ESC key is pressed
    }
    else {
        mario.setPoints(board);
        if (key == 'w' && !mario.getIsOnLadder()) {
            mario.jump(board);
        }
        else {
            mario.changeDir(key); // Change Mario's direction based on input
            if (mario.check_next_pos_valid(board, key)) {
                mario.move(board, key); // Move Mario if the next position is valid
            }
        }
  
    }
}


// Pause the game and wait for ESC to resume
void Game::pauseGame() {
    system("cls"); // Clear the screen
    gotoxy(static_cast<int>(boardCenter::X), static_cast<int>(boardCenter::Y));
    std::cout << "Game Paused, press ESC again to continue.";

    while (true) {
        if (_kbhit()) {
            char nextKey = _getch();
            if (static_cast<GameConfig::eKeys>(nextKey) == GameConfig::eKeys::ESC) {
                system("cls"); // Clear the screen
                board.printArrChar(); // Reprint the current state of the board
                break;
            }
        }
    }
}

// Handle the player's death by resetting Mario's position and delaying
void Game::handleDeath() {
    mario.reset_character(pac_reset, board); // Reset Mario's position
    Sleep(1500); // Brief delay to allow the player to see the death
}

// Placeholder for death-check logic
void Game::check_if_died() {
    // Add logic here to check if the player died
}
