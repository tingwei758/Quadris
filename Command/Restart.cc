#include "Restart.h"

Restart::Restart(Game *game):game{game}{}

void Restart::execute(){
	game->restart();
}
