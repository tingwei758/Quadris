#ifndef __GRAPHICSDISPLAY_H__
#define __GRAPHICSDISPLAY_H__

#define AMPLIFIER 30
#include <iostream>

#include "window.h"
#include "../Board/Board.h"
#include "../Game/Score.h"
#include "../Level/Level.h"

class GraphicsDisplay {
	Board *board;
	Score *score;
	Level **level;
	char *nextBlock;
	Xwindow w;

public:
	GraphicsDisplay(Board *board, Score *score, Level **level, char *nextBlock);

	void displayBoard(); // display board section
	void displayScoreBoard(); // display score section
	void displayNextBlock(); // display next section
	
	void display();
};

#endif
