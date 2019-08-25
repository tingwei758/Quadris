#ifndef __RESTART_H__
#define __RESTART_H__

#include "../Game/Game.h"
#include "Command.h"

class Restart : public Command {
	Game *game;
public:
	Restart(Game *game);
	void execute() override;
};

#endif
