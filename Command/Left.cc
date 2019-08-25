#include "Left.h"

Left::Left(Game *game):game{game}{}

void Left::execute(){
	game->left();
}
