#include "menu.h"

// Main menu function to navigate through the game options
void Menu::run_main() {
    int choice = 0;  // Variable to store the user's menu choice

    while (true) {
        // Display the main menu
        std::cout << "===== Main Menu =====" << std::endl;
        std::cout << "1. Start a new Game" << std::endl;
        std::cout << "8. Present instructions and keys" << std::endl;
        std::cout << "9. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Handle the user's choice using a switch-case
        switch (choice) {
        case START:  // If the user chooses to start a new game
            system("cls");  // Clear the console screen
            game.run_game();  // Run the game
            break;

        case INSTRUCTIONS:  // If the user chooses to view the instructions
            system("cls");  // Clear the console screen
            instructions.show_instructions();  // Show the instructions
            break;

        case EXIT:  // If the user chooses to exit
            system("cls");  // Clear the console screen
            std::cout << "Exiting program. Goodbye!" << std::endl;
            return;  // Exit the loop and the program

        default:  // If the user enters an invalid option
            system("cls");  // Clear the console screen
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    endGame();  // Display the end game message (though this line is technically unreachable due to return)
}

// Function to display the game over message at the end of the game
void Menu::endGame() {
    system("cls");  // Clear the screen
    gotoxy(35, 15);  // Move the cursor to position (35, 15) for a centered message
    std::cout << "GAME OVER";  // Display "GAME OVER" message
}
