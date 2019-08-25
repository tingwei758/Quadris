#ifndef __UP_H__
#define __UP_H__

#include "../Game/Game.h"
#include "Command.h"

class Up : public Command {
	Game *game;
public:
	Up(Game *game);
	void execute() override;
};

#endif
