#include "Clockwise.h"

Clockwise::Clockwise(Game* pg){
    this->game = pg;
}

void Clockwise::execute(){
    this->game->clockwise();
}

