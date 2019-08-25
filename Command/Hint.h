#ifndef __HINT_H__
#define __HINT_H__

#include "../Game/Game.h"
#include "Command.h"

class Hint : public Command {
	Game *game;
public:
	Hint(Game *game);
	void execute() override;
};

#endif
