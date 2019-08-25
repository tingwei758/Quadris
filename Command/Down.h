#ifndef __DOWN_H__
#define __DOWN_H__
#include "../Game/Game.h"
#include "Command.h"

class Down : public Command {
        Game* game;
public:
        Down(Game*);
	void execute() override;
};

#endif
