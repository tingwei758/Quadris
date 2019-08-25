
#ifndef __COUNTERCLOCKWISE_H__
#define __COUNTERCLOCKWISE_H__
#include "../Game/Game.h"
#include "Command.h"

class Counterclockwise : public Command {
    Game* game;
public:
    Counterclockwise(Game*);
    void execute() override;
};

#endif

