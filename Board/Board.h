#ifndef __BOARD_H__
#define __BOARD_H__

#include <vector>
#include <iostream>

#include "Cell.h"

class Board{

	// the most top-left cell's (x,y) is (0,height)
	int height;
	int width;

public:
	std::vector <std::vector <Cell>> board;

	int getHeight();
	int getWidth();

	Board(int height, int width);
	Cell &getCell(int, int);
	void setCell(int, int, char);
	void clear();
	// line 0 is the most top one
	void clearLine(int line);
	bool isLineFull(int line);
	friend std::ostream &operator<<(std::ostream &out, Board &b);
};

#endif


