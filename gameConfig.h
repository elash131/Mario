#pragma once

class GameConfig
{
public:
	enum class eKeys { LEFT = 'a', RIGHT = 'd', UP = 'w', DOWN = 'x', ESC = 27, STAY = 's' };
	enum class EntitySigns {
		MARIO = '@',
		LADDER = 'H',
		FLOOR1 = '=',
		FLOOR2 = '<',
		FLOOR3 = '>',
		WALL = 'Q',
		EMPTY = ' '
	};
	static char getEntitySign(EntitySigns sign) { return static_cast<char>(sign); }
	static constexpr int GAME_WIDTH = 20;
	static constexpr int GAME_HEIGHT = 20;
	static constexpr int lives = 3;
	static constexpr int MIN_X = 10;
	static constexpr int MIN_Y = 3;

	static const int COLORS[];
	static const int NUM_OF_COLORS;
};
