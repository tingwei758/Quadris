#ifndef __LEFT_H__
#define __LEFT_H__
#include "Command.h"
#include "../Game/Game.h"

class Left : public Command {
	Game *game;
public:
	Left(Game *game);
	void execute() override;
};

#endif
