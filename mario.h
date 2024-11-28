#pragma once
#include "character.h"
#include "point.h"

class Mario : public Character {
    int score = 0;  // Mario's score

public:
    // Constructor with default starting position and symbol for Mario
    Mario(int x_ = 3, int y_ = 22, char sign_ = '@') : Character(x_, y_, sign_) {}

    // Override move function to define how Mario moves
    void move(Board& b, char dir) override;

    // Getter for Mario's score
    int get_score() const { return score; }

    // Check if the next position is valid (e.g., no walls or ladders)
    bool check_next_pos_valid(const Board& b, char dir) override;

    // Reset Mario's position and state
    void reset_character(Point& p, Board& b) override;
    void fall(Board& b);
    // Change direction based on user input (dir: 'w', 'a', 's', 'd')
    void changeDir(char dir);
    void setPoints(const Board& b);
    void jump(Board& b);
    void clearMarioPosition(Board& b) const;
    void updateMarioPosition(Board& b) const;
    void jumpInPlace(Board& b);
    void jumpInMotion(Board& b);
};
