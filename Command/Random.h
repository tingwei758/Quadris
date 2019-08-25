#ifndef __RANDOM_H__
#define __RANDOM_H__

#include "../Game/Game.h"
#include "Command.h"

class Random : public Command {
	Game *game;
public:
	Random(Game *game);
	void execute() override;
};

#endif
