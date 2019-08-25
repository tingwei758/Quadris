#ifndef __LEVELUP_H__
#define __LEVELUP_H__
#include "../Game/Game.h"
#include "Command.h"

class Levelup : public Command {
    Game* game;
public:
    Levelup(Game*);
    void execute() override;
};

#endif

