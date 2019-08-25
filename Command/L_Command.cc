#include "L_Command.h"

L_Command::L_Command(Game *game):game{game}{}

void L_Command::execute(){
	game->L();
}
