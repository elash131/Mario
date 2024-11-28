#include "mario.h"

void Mario::changeDir(char dir) {

	// Convert the input char (dir) to the corresponding eKeys enum value using static_cast
	GameConfig::eKeys key = static_cast<GameConfig::eKeys>(dir);

	// Switch statement to handle different key presses
	switch (key) {
	case GameConfig::eKeys::UP: // If 'w' is pressed, move up
		setDirX(0);  // No change in the X direction
		setDirY(-1); // Move up by decreasing Y
		break;
	case GameConfig::eKeys::LEFT: // If 'a' is pressed, move left
		setDirX(-1); // Move left by decreasing X
		setDirY(0);  // No change in the Y direction
		break;
	case GameConfig::eKeys::DOWN: // If 'x' is pressed, move down
		setDirX(0);  // No change in the X direction
		setDirY(1);  // Move down by increasing Y
		break;
	case GameConfig::eKeys::RIGHT: // If 'd' is pressed, move right
		setDirX(1);  // Move right by increasing X
		setDirY(0);  // No change in the Y direction
		break;
	case GameConfig::eKeys::STAY: // 's' key to stop
		setDirX(0);
		setDirY(0);
		break;
	default:
		// If no valid key is pressed, do nothing
		break;
	}
}

void Mario::reset_character(Point& p, Board& b)
{
	// Clear Mario's previous position by using the EMPTY sign
	updateCharacterDisplay(GameConfig::getEntitySign(GameConfig::EntitySigns::EMPTY));

	setX(p.getX());
	setY(p.getY());

	// Set Mario's sign to '@' and his character sign to '@'
	change_point_sign(GameConfig::getEntitySign(GameConfig::EntitySigns::MARIO));
	updateCharacterDisplay(GameConfig::getEntitySign(GameConfig::EntitySigns::MARIO));
}

void Mario::fall(Board& b) {
	bool hasFallen = false; // Flag to check if a fall occurred
	setPoints(b);
	// Continue falling as long as there is no floor below Mario
	while (!getisFloorBelow()) {
		hasFallen = true; // Mark that Mario has fallen

		// Clear Mario's current position from the board
		b.change_sign(getY(), getX(), GameConfig::getEntitySign(GameConfig::EntitySigns::EMPTY));
		change_point_sign(GameConfig::getEntitySign(GameConfig::EntitySigns::EMPTY));
		updateCharacterDisplay(GameConfig::getEntitySign(GameConfig::EntitySigns::EMPTY));
		// Update Mario's position (move one step down)
		setY(getY() + 1);

		// Place Mario at the new position on the board
		b.change_sign(getY(), getX(), GameConfig::getEntitySign(GameConfig::EntitySigns::MARIO));
		change_point_sign(GameConfig::getEntitySign(GameConfig::EntitySigns::MARIO));
		updateCharacterDisplay(GameConfig::getEntitySign(GameConfig::EntitySigns::MARIO));

		// Wait for 150ms to simulate the falling animation
		Sleep(150);
		setPoints(b);
	}

	// Reset Mario's directions only if a fall occurred
	if (hasFallen) {
		setDirX(0);
		setDirY(0);
	}
}


void Mario::move(Board& b, char dir) {
	// Check if the next position is valid
	if (check_next_pos_valid(b, dir)) {
		// Remove Mario's current position from the board
		if (getIsOnLadder()) {
			b.change_sign(getY(), getX(), GameConfig::getEntitySign(GameConfig::EntitySigns::LADDER));
			// Reset Mario's point and character sign
			change_point_sign(GameConfig::getEntitySign(GameConfig::EntitySigns::LADDER));
			updateCharacterDisplay(GameConfig::getEntitySign(GameConfig::EntitySigns::LADDER));
		}
		else {
			b.change_sign(getY(), getX(), GameConfig::getEntitySign(GameConfig::EntitySigns::EMPTY));
			// Reset Mario's point and character sign
			change_point_sign(GameConfig::getEntitySign(GameConfig::EntitySigns::EMPTY));
			updateCharacterDisplay(GameConfig::getEntitySign(GameConfig::EntitySigns::EMPTY));
		}
		// Update Mario's position based on direction
		changeXandY();

		// Handle wrap-around for edges
		if (getX() > max_x) setX(min_x);
		else if (getX() < min_x) setX(max_x);
		if (getY() > max_y) setY(min_y);
		else if (getY() < min_y) setY(max_y);

		// Place Mario on the new position
		b.change_sign(getY(), getX(), GameConfig::getEntitySign(GameConfig::EntitySigns::MARIO));
		change_point_sign(GameConfig::getEntitySign(GameConfig::EntitySigns::MARIO));
		updateCharacterDisplay(GameConfig::getEntitySign(GameConfig::EntitySigns::MARIO));
	}
	else {
		// Stop movement if the next position is invalid
		setDirX(0);
		setDirY(0);
	}
}

bool Mario::check_next_pos_valid(const Board& b, char dir)
{
	bool isValid = false;
	setPoints(b);
	// Convert the input char (dir) to the corresponding eKeys enum value using static_cast
	GameConfig::eKeys key = static_cast<GameConfig::eKeys>(dir);
	// Switch statement to handle different key presses
	switch (key) {
	case GameConfig::eKeys::UP: // If 'w' is pressed, move up
		isValid = getIsOnLadder() && (getisLadderNext() || getisLadderBelow());
		break;
	case GameConfig::eKeys::DOWN: // If 'x' is pressed, move down
		isValid = getisLadderBelow();
		break;
	default:
		// Check if the next position is not a wall and has floor
		//isValid = !getisWallNext() && (getisFloorBelowNext());
		isValid = !getisWallNext();
		break;
	}
	return isValid;
}

void Mario::setPoints(const Board& b)
{
	setBelowPos(b);
	setNextPos(b);
	setCurrPos(b);
	setBelowNextPos(b);
}

void Mario::jump(Board& b) {

	// Clear Mario's current position from the board
	clearMarioPosition(b);

	// Check if Mario is in motion (moving left or right)
	if (getDirX() != 0) {
		jumpInMotion(b);
	}
	else {
		jumpInPlace(b);
	}
}
// Helper function to clear Mario's current position
void Mario::clearMarioPosition(Board& b) const {
	
	b.change_sign(getY(), getX(), GameConfig::getEntitySign(GameConfig::EntitySigns::EMPTY));
	updateCharacterDisplay(GameConfig::getEntitySign(GameConfig::EntitySigns::EMPTY));
}

// Helper function to update Mario's position
void Mario::updateMarioPosition(Board& b) const {
	b.change_sign(getY(), getX(), GameConfig::getEntitySign(GameConfig::EntitySigns::MARIO));
	updateCharacterDisplay(GameConfig::getEntitySign(GameConfig::EntitySigns::MARIO));
}
void Mario::jumpInPlace(Board& b) {
	// Perform the jump: 2 steps up, then 2 steps down
	for (int step = 0; step < 4; ++step) {
		int direction = (step < 2) ? -1 : 1; // First 2 steps go up (-1), last 2 steps go down (+1)
		setY(getY() + direction);           // Update Y position based on direction
		updateMarioPosition(b);             // Display Mario's new position
		Sleep(150);                         // Delay for animation effect
		if (step < 3) clearMarioPosition(b); // Clear Mario's position for next frame, but not on the final step
	}
}

// Function to handle Mario's jump while in motion
void Mario::jumpInMotion(Board& b) {
	// Perform the jump: 2 steps up, horizontal motion, then 2 steps down
	for (int step = 0; step < 4; ++step) {
		if (step < 2) {
			setY(getY() - 1); // First 2 steps go up
		}
		else if (step == 2) {
			setX(getX() + (getDirX() * 2)); // Horizontal motion in the direction of movement
			setY(getY() + 1);               // Start moving down
		}
		else {
			setY(getY() + 1); // Continue moving down
		}

		updateMarioPosition(b); // Update Mario's position on the board
		Sleep(150);             // Add delay for animation

		// Clear Mario's position, except after the last step
		if (step < 3) {
			clearMarioPosition(b);
		}
	}
}

