#include <cstring>
#include <iostream>

#include "Board.h"

// Print the 2D `arrChar` array (character representation of the board)
void Board::printArrChar() {
    for (int i = 0; i < boardEnum::ROWS; i++) {  // Loop through rows
        for (int j = 0; j < boardEnum::COLS; j++) {  // Loop through columns
            std::cout << arrChar[i][j];  // Print each character at arrChar[i][j]
        }
        std::cout << "\n";  // Move to the next line after printing one row
    }
}

// Fill the `arrPoint` array with Point objects based on `arrChar`
void Board::insertDataToArrPoint() {
    for (int i = 0; i < boardEnum::ROWS; i++) {  // Loop through rows
        for (int j = 0; j < boardEnum::COLS; j++) {  // Loop through columns
            insertDataToAPoint(j, i, arrChar[i][j], arrPoint[i][j]);  // Insert data into Point
        }
    }
}

// Print the board using the `arrPoint` array, calling each point's `getSign` method
void Board::printArrPoint() {
    for (int i = 0; i < boardEnum::ROWS; i++) {  // Loop through rows
        for (int j = 0; j < boardEnum::COLS; j++) {  // Loop through columns
            std::cout << arrPoint[i][j].getSign();  // Print the sign of the point
        }
        std::cout << "\n";  // Move to the next line after printing one row
    }
}

// Helper function to insert data into a specific Point (x, y, sign) and update its state
void Board::insertDataToAPoint(int x, int y, char sign, Point& p) {
    p.setX(x);  // Set the X-coordinate of the point
    p.setY(y);  // Set the Y-coordinate of the point
    p.setSign(sign);  // Set the sign/character representation of the point
    p.checkSign();  // Check if the sign corresponds to a special entity (ladder, wall, etc.)
}

// Print the current score (currently commented out)
void Board::print_score() {
    gotoxy(85, 0);  // Position the cursor at (85, 0)
    //std::cout << "max score: " << bread_crumbs_amount;  // Print the score (currently commented out)
}

// Return a Point object based on its row and column index in `arrPoint`
Point Board::get_point_by_index(int row, int col) const {
    Point p = arrPoint[row][col];  // Return the Point at the specified (row, col) position
    return p;
}
