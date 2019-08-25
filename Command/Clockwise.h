
#ifndef __CLOCKWISE_H__
#define __CLOCKWISE_H__
#include "../Game/Game.h"
#include "Command.h"

class Clockwise : public Command {
    Game* game;
public:
    Clockwise(Game*);
    void execute() override;
};

#endif

