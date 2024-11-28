#include "character.h"

void Character::setNextPos(const Board& b)
{
	next_pos = b.get_point_by_index((getY() + dirY), (getX() + dirX));
}
void Character::setBelowPos(const Board& b)
{
	below_pos = b.get_point_by_index((getY() + 1), getX());
}
void Character::setCurrPos(const Board& b)
{
	curr_pos = b.get_point_by_index(getY(), getX());
}
void Character::setBelowNextPos(const Board& b)
{
	below_next_pos = b.get_point_by_index((getY() + 1), getX() + dirX);
}
void Character::changeXandY()
{
	int new_X = getX() + dirX;
	int new_Y = getY() + dirY;
	setX(new_X);
	setY(new_Y);
}
void Character::changeRandDir()
{
	size_t rand_num = rand() % 4 + 1;
	switch (rand_num)
	{
	case 1: //up
		dirX = 0;
		dirY = -1;
		break;
	case 3: //left
		dirX = -1;
		dirY = 0;
		break;
	case 2: // down
		dirX = 0;
		dirY = 1;
		break;
	case 4: // right
		dirX = 1;
		dirY = 0;
		break;
	default:
		break;
	}
}

bool Character::operator==(const Character& c)
{
	if (curr_pos == c.curr_pos) {
		return true;
	}
	return false;
}
