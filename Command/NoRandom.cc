#include "NoRandom.h"

NoRandom::NoRandom(Game *game, std::string filename):game{game},filename{filename}{}

void NoRandom::execute(){
	game->norandom(filename);
}
