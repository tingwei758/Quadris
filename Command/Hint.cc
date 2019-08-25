#include "Hint.h"

Hint::Hint(Game *game):game{game}{}

void Hint::execute(){
	game->hint();
}
