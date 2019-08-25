#ifndef __DROP_H__
#define __DROP_H__
#include "../Game/Game.h"
#include "Command.h"

class Drop : public Command {
        Game* game;
public:
	Drop(Game*);
	void execute() override;
};

#endif
