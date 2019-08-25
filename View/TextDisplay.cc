#include "TextDisplay.h"

TextDisplay::TextDisplay(Board *board, Score *score, Level **level, char* nextBlock):
board{board},score{score},level{level},nextBlock{nextBlock}{}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td){

	out << **(td.level);
	out << *(td.score);
	out << "+-----------+" << std::endl;

	out << *(td.board);

	out << "+-----------+" << std::endl;

	out << "Next:" << std::endl;

	switch(*(td.nextBlock)) {
		case 'I':
		out << "    "<< std::endl;
		out << "IIII" << std::endl;
		break;
		case 'J':
		out << "J  " << std::endl;
		out << "JJJ" << std::endl;
		break;
		case 'L':
		out << "  L" << std::endl;
		out << "LLL" << std::endl;
		break;
		case 'O':
		out << "OO" << std::endl;
		out << "OO" << std::endl;
		break;
		case 'S':
		out << " SS" << std::endl;
		out << "SS " << std::endl;
		break;
		case 'Z':
		out << "ZZ " << std::endl;
		out << " ZZ" << std::endl;
		break;
		case 'T':
		out << " T " << std::endl;
		out << "TTT" << std::endl;
		break;
		default:
		out << std::endl;
		out << std::endl;
		break;

	}//end switch

	return out;
}
