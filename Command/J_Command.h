#ifndef __J_COMMAND_H__
#define __J_COMMAND_H__

#include "../Game/Game.h"
#include "Command.h"

class J_Command : public Command {
	Game *game;
public:
	J_Command(Game *game);
	void execute() override;
};

#endif
