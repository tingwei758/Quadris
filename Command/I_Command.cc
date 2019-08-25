#include "I_Command.h"

I_Command::I_Command(Game *game):game{game}{}

void I_Command::execute(){
	game->I();
}
