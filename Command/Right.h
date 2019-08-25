#ifndef __RIGHT_H__
#define __RIGHT_H__
#include "../Game/Game.h"
#include "Command.h"

class Right : public Command {
        Game* game;
public:
        Right(Game*);
	void execute() override;
};

#endif
