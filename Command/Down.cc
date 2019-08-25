#include "Down.h"

Down::Down(Game* pg){
    this->game = pg;
}

void Down::execute(){
    this->game->down();
}
	
