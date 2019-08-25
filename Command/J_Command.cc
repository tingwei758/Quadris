#include "J_Command.h"

J_Command::J_Command(Game *game):game{game}{}

void J_Command::execute(){
	game->J();
}
