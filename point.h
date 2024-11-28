#pragma once
#include "gameConfig.h"
#include <iostream>
#include "utils.h"

class Point {
    // Static array holding key mappings ('w', 'a', 'x', 'd', 's')
    static constexpr char keys[] = { 'w', 'a', 'x', 'd', 's' };

    // Calculate the number of keys in the array
    static constexpr size_t numKeys = sizeof(keys) / sizeof(keys[0]);

    // Struct to represent direction in terms of x and y coordinates
    struct Direction {
        int x, y;
    };

    // Static array holding direction mappings corresponding to the 'keys' array
    static constexpr Direction directions[] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0}, {0, 0} };

    // Instance variables for position (x, y), sign, and flags for wall, visit, and ladder
    int x = 3, y = 1;
    char sign;
    bool isWall = false;
    bool isVisit = false;
    bool isLadder = false;
    bool isFloor = false;

    Direction dir{ 0, 0 };  // Current direction (x, y) for movement

    // Helper function to draw a character at the point's position
    void draw(char c) const {
        gotoxy(x, y);  // Move the cursor to the point's position
        std::cout << c;  // Draw the character at that position
    }

public:
    // Constructor to initialize the point with default or given position and sign
    Point(int x_ = 35, int y_ = 10, char sign_ = '@') : x(x_), y(y_), sign(sign_) {}

    // Getter methods
    bool getIsVisit() const { return isVisit; }  // Return if the point has been visited
    bool getisWall() const { return isWall; }    // Return if the point is a wall
    bool getisLadder() const { return isLadder; }  // Return if the point is a ladder
    bool getisFloor () const { return isFloor; }  // Return if the point is a ladder

    // Getter methods for position and sign
    int getX() const { return x; }
    int getY() const { return y; }
    char getSign() const { return sign; }

    // Setter methods to update position and sign
    void setX(int x_) { x = x_; }
    void setY(int y_) { y = y_; }
    void setSign(char sign_) { sign = sign_; }

    // Function to check the sign and update the point's attributes (wall, ladder)
    void checkSign();

    // Overloaded equality operator to compare two points
    bool operator==(const Point& p) {
        return (x == p.x && y == p.y);  // Return true if the points have the same position
    }
};
