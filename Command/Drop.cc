#include "Drop.h"

Drop::Drop(Game* pg){
    this->game = pg;
}

void Drop::execute(){
    this->game->drop();
}

