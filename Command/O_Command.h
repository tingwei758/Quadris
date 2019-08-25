#ifndef __O_COMMAND_H__
#define __O_COMMAND_H__

#include "../Game/Game.h"
#include "Command.h"

class O_Command : public Command {
	Game *game;
public:
	O_Command(Game *game);
	void execute() override;
};

#endif
