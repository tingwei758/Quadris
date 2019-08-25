#include "Leveldown.h"

Leveldown::Leveldown(Game* pg){
    this->game = pg;
}

void Leveldown::execute(){
    this->game->leveldown();
}

