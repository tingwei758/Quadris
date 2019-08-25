
#ifndef __LEVELDOWN_H__
#define __LEVELDOWN_H__
#include "../Game/Game.h"
#include "Command.h"

class Leveldown : public Command {
    Game* game;
public:
    Leveldown(Game*);
    void execute() override;
};

#endif

