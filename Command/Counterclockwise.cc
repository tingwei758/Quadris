#include "Counterclockwise.h"

Counterclockwise::Counterclockwise(Game* pg){
    this->game = pg;
}

void Counterclockwise::execute(){
    this->game->counterclockwise();
}

