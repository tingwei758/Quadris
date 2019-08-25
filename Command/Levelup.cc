#include "Levelup.h"

Levelup::Levelup(Game* pg){
    this->game = pg;
}

void Levelup::execute(){
    this->game->levelup();
}

