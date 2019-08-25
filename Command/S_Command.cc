#include "S_Command.h"

S_Command::S_Command(Game *game):game{game}{}

void S_Command::execute(){
	game->S();
}
