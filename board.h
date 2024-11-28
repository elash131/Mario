#pragma once
#include <iostream>
#include "point.h"
class Board {
	enum boardEnum { ROWS = 25, COLS = 80 };
	Point arrPoint[ROWS][COLS];

	char arrChar[ROWS][COLS] = {
	  // 01234567890123456789012345678901234567890123456789012345678901234567890123456789
		"QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ", // 0
		"Q                                                                             Q", // 1
		"Q                    H===================================H                    Q", // 2
		"Q    ===H=========   H                                   H              H     Q", // 3
		"Q       H            H                                   H              H     Q", // 4
		"Q       H            H                                   H<<<===========H=====Q", // 5
		"Q=======H=========>>>H=== ===========H====== ========<<<=H              H     Q", // 6
		"Q                                    H                                  H     Q", // 7
		"Q                                    H                                  H     Q", // 8
		"Q                       =<<<=========H             H======= =======H========  Q", // 9
		"Q                                    H             H               H          Q", // 10
		"Q                                    H======>>>====H               H          Q", // 11
		"Q     =============H=>>>             H             H               H          Q", // 12
		"Q                  H                 H         ====H=====H<<<======H===       Q", // 13
		"Q                  H                 H                   H         H          Q", // 14
		"Q                  H                 H                   H         H          Q", // 15
		"Q                  H        ==H======H======<<<==========H         H          Q", // 16
		"Q                  H          H                                    H          Q", // 17
		"Q                  H          H                                    H          Q", // 18
		"Q                ==H==<<<>>>==H=                        ===========H======    Q", // 19
		"Q                  H          H                                               Q", // 20
		"Q                  H          H                                               Q", // 21
		"Q  @               H          H                                               Q", // 22
		"Q======>>>==========================================================<<<=======Q", // 23
		"QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ"  // 24
	
	};
public:
	void change_sign(int row, int col, char sign) {
		arrPoint[row][col].setSign(sign);
	}
	bool check_if_is_visit(int row, int col) {
		return arrPoint[row][col].getIsVisit();
	}

	void printArrChar();
	void printArrPoint();
	void insertDataToArrPoint();
	void insertDataToAPoint(int x, int y, char sign, Point& p);
	void print_score();
	Point get_point_by_index(int row, int col) const;
};

