#ifndef __TEXT_DISPLAY_H_
#define __TEXT_DISPLAY_H_

#include <iostream>

#include "../Board/Board.h"
#include "../Game/Score.h"
#include "../Level/Level.h"

class TextDisplay {
	Board *board;
	Score *score;
	Level **level;
	char* nextBlock;
public:
	TextDisplay(Board *board, Score *score, Level **level, char* nextBlock);
	friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
