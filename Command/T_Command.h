#ifndef __T_COMMAND_H__
#define __T_COMMAND_H__

#include "../Game/Game.h"
#include "Command.h"

class T_Command : public Command {
	Game *game;
public:
	T_Command(Game *game);
	void execute() override;
};

#endif
