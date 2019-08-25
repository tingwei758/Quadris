#ifndef __NORANDOM_H__
#define __NORANDOM_H__

#include "../Game/Game.h"
#include "Command.h"
#include <string>

class NoRandom : public Command {
	Game *game;
	std::string filename;
public:
	NoRandom(Game *game, std::string filename);
	void execute() override;
};

#endif
