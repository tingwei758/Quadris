#include "T_Command.h"

T_Command::T_Command(Game *game):game{game}{}

void T_Command::execute(){
	game->T();
}
