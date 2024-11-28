#pragma once
#include "point.h"
#include "board.h"

using namespace::std;
class Character
{
	// Direction of the character's movement (X and Y)
	int dirX = 0, dirY = 0;

	// Current and next position of the character
	Point curr_pos, next_pos;
	Point below_pos, below_next_pos;

	// Constants for possible movement directions
	enum { up = 1, down = 2, left = 3, right = 4 };

public:
	// Constructor initializes current position with x, y and a character sign
	Character(int x_, int y_, char sign_) : curr_pos(x_, y_, sign_) {}

	// Boundaries for movement on the board
	enum { min_x = 0, max_x = 78, min_y = 0, max_y = 24 };

	// Getters for current position and direction
	int getX() const { return curr_pos.getX(); }
	int getY() const { return curr_pos.getY(); }
	int getDirY() const { return dirY; }
	int getDirX() const { return dirX; }
	char getSign() const { return curr_pos.getSign(); }
	//int getNextPos() const { return next_pos.getX(); }

	// Get the sign of the next position
	char getSignNextPos() { return next_pos.getSign(); }

	// Check if the current and next positions have been visited
	bool getIsVisitNext() { return next_pos.getIsVisit(); }
	bool getIsVisitCurr() { return curr_pos.getIsVisit(); }

	// Check for walls or ladders in the next position
	bool getisWallNext() { return next_pos.getisWall(); }
	bool getisFloorBelow() { return below_pos.getisFloor(); }
	bool getisFloorBelowNext() { return below_next_pos.getisFloor(); }
	bool getIsOnLadder() { return curr_pos.getisLadder(); }
	bool getisLadderNext() { return next_pos.getisLadder(); }
	bool getisLadderBelow() { return below_pos.getisLadder(); }

	// Set next position based on the current board
	void setNextPos(const Board& b);
	void setBelowPos(const Board& b);
	void setCurrPos(const Board& b);
	void setBelowNextPos(const Board& b);

	// Setters for direction and position
	void setDirX(int dir) { dirX = dir; }
	void setDirY(int dir) { dirY = dir; }
	void setX(int x_) { curr_pos.setX(x_); }
	void setY(int y_) { curr_pos.setY(y_); }
	void setSign(char sign_) { curr_pos.setSign(sign_); }

	// Method to change the X and Y coordinates
	void changeXandY();

	// Update the character's position sign in the console
	void change_point_sign(char sign) {
		curr_pos.setSign(sign);
	}

	// Output the character's sign at the current position in the console
	void updateCharacterDisplay(char sign) const {
		gotoxy(getX(), getY());
		cout << sign;
	}

	// Change the direction of movement randomly (for AI or random behavior)
	void changeRandDir();

	// Comparison operator to check if two characters are at the same position
	bool operator==(const Character& c);

	// Abstract methods to be implemented in derived classes
	virtual void reset_character(Point& p, Board& b) = 0;  // Reset the character's state
	virtual void move(Board& b, char dir) = 0;                        // Move the character
	virtual bool check_next_pos_valid(const Board& b, char dir) = 0;  // Check if the next move is valid

	// Getter for current position
	Point get_curr_pos() { return curr_pos; }


};

