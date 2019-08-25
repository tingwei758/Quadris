#include "O_Command.h"

O_Command::O_Command(Game *game):game{game}{}

void O_Command::execute(){
	game->O();
}
