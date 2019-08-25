#ifndef __SEQUENCE_H__
#define __SEQUENCE_H__

#include "../Game/Game.h"
#include "Command.h"

class Sequence : public Command {
	Game *game;
public:
	Sequence(Game *game);
	void execute() override;
};

#endif
