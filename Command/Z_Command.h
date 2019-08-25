#ifndef __Z_COMMAND_H__
#define __Z_COMMAND_H__

#include "../Game/Game.h"
#include "Command.h"

class Z_Command : public Command {
	Game *game;
public:
	Z_Command(Game *game);
	void execute() override;
};

#endif
