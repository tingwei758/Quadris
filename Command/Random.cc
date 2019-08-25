#include "Random.h"

Random::Random(Game *game):game{game}{}

void Random::execute(){
	game->random();
}
