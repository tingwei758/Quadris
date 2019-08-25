#include "Sequence.h"

Sequence::Sequence(Game *game):game{game}{}

void Sequence::execute(){
	game->sequence("123");
}
