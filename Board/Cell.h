#ifndef __CELL_H__
#define __CELL_H__

#include "../Pattern/Subject.h"
#include "CellState.h"

class Cell : public Subject{
	CellState state;
public:
	Cell(int x, int y);
	CellState &getState();
	void setSymbol(char symbol);
};

#endif
