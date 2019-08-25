#include "Right.h"

Right::Right(Game* pg){
    this->game = pg;
}

void Right::execute(){
    this->game->right();
}	
