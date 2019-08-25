#include "Z_Command.h"

Z_Command::Z_Command(Game *game):game{game}{}

void Z_Command::execute(){
	game->Z();
}
