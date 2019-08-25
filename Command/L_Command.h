#ifndef __L_COMMAND_H__
#define __L_COMMAND_H__

#include "../Game/Game.h"
#include "Command.h"

class L_Command : public Command {
	Game *game;
public:
	L_Command(Game *game);
	void execute() override;
};

#endif
