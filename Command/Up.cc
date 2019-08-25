#include "Up.h"

Up::Up(Game *game):game{game}{}

void Up::execute(){
	game->up();
}
