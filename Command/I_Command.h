#ifndef __I_COMMAND_H__
#define __I_COMMAND_H__

#include "../Game/Game.h"
#include "Command.h"

class I_Command : public Command {
	Game *game;
public:
	I_Command(Game *game);
	void execute() override;
};

#endif
