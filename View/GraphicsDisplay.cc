#include "GraphicsDisplay.h"
#include <string>
#include <sstream>

GraphicsDisplay::GraphicsDisplay(Board *board, Score *score, Level **level, char* nextBlock):
board{board},score{score},level{level},nextBlock{nextBlock}{

	// board background
	w.fillRectangle(0, 0, board->getWidth()*AMPLIFIER, board->getHeight()*AMPLIFIER, Xwindow::White);

	// other background
	w.fillRectangle(board->getWidth()*AMPLIFIER,0,
		(board->getHeight()-board->getWidth()-1)*AMPLIFIER,board->getHeight()*AMPLIFIER, Xwindow::Blue);

	// nextblock section background
	w.fillRectangle(board->getWidth()*AMPLIFIER,2*AMPLIFIER,
		(board->getHeight()-board->getWidth()-1)*AMPLIFIER,4*AMPLIFIER, Xwindow::White);

	w.drawBigString(board->getWidth()*AMPLIFIER,15*AMPLIFIER/10, "Next:", Xwindow::Black);

	displayNextBlock();

	displayScoreBoard();

}


void GraphicsDisplay::display(){

	displayNextBlock();

	displayBoard();

	displayScoreBoard();

}

void GraphicsDisplay::displayBoard(){

	for (int i = 0; i < board->getHeight(); ++i){
		for (int j = 0; j < board->getWidth(); ++j){

			Cell cell = board->getCell(j,i);
			char sym = cell.getState().symbol;

			switch(sym){
				case 'I':
				w.fillRectangle(j*AMPLIFIER,i*AMPLIFIER,
					AMPLIFIER,AMPLIFIER, Xwindow::Cyan);
				break;
				case 'J':
				w.fillRectangle(j*AMPLIFIER,i*AMPLIFIER,
					AMPLIFIER,AMPLIFIER, Xwindow::Blue);
				break;
				case 'L':
				w.fillRectangle(j*AMPLIFIER,i*AMPLIFIER,
					AMPLIFIER,AMPLIFIER, Xwindow::Orange);
				break;
				case 'O':
				w.fillRectangle(j*AMPLIFIER,i*AMPLIFIER,
					AMPLIFIER,AMPLIFIER, Xwindow::Yellow);
				break;
				case 'S':
				w.fillRectangle(j*AMPLIFIER,i*AMPLIFIER,
					AMPLIFIER,AMPLIFIER, Xwindow::Green);
				break;
				case 'Z':
				w.fillRectangle(j*AMPLIFIER,i*AMPLIFIER,
					AMPLIFIER,AMPLIFIER, Xwindow::Red);
				break;
				case 'T':
				w.fillRectangle(j*AMPLIFIER,i*AMPLIFIER,
					AMPLIFIER,AMPLIFIER, Xwindow::Magenta);
				break;
				case '?':
				w.fillRectangle(j*AMPLIFIER,i*AMPLIFIER,
					AMPLIFIER,AMPLIFIER, Xwindow::Black);
				break;
				case '*':
				w.fillRectangle(j*AMPLIFIER,i*AMPLIFIER,
					AMPLIFIER,AMPLIFIER, Xwindow::Brown);
				break;
				default:
				w.fillRectangle(j*AMPLIFIER,i*AMPLIFIER,
					AMPLIFIER,AMPLIFIER, Xwindow::White);
				break;

			}//end switch
		}// end j loop
	}// end i loop

}

void GraphicsDisplay::displayScoreBoard(){

	// display score section
	w.fillRectangle(board->getWidth()*AMPLIFIER,9*AMPLIFIER,
		(board->getHeight()-board->getWidth()-1)*AMPLIFIER,7*AMPLIFIER, Xwindow::Yellow);

	// display the game info
	w.drawBigString(board->getWidth()*AMPLIFIER,10*AMPLIFIER, "Level:", Xwindow::Black);
	w.drawBigString(board->getWidth()*AMPLIFIER,12*AMPLIFIER, "Score:", Xwindow::Black);
	w.drawBigString(board->getWidth()*AMPLIFIER,15*AMPLIFIER, "Hi Score:", Xwindow::Black);

	// display score
	w.drawBigString(board->getWidth()*AMPLIFIER,13*AMPLIFIER, std::to_string(score->getScore()), Xwindow::Black);
	w.drawBigString(board->getWidth()*AMPLIFIER,16*AMPLIFIER, std::to_string(score->getHighScore()), Xwindow::Black);

	// display level
	w.drawBigString(15*AMPLIFIER,10*AMPLIFIER, std::to_string((*level)->getLevel()), Xwindow::Black);

}

void GraphicsDisplay::displayNextBlock(){


	w.fillRectangle(board->getWidth()*AMPLIFIER,2*AMPLIFIER,
		(board->getHeight()-board->getWidth()-1)*AMPLIFIER,4*AMPLIFIER, Xwindow::White);

	switch(*nextBlock) {
		case 'I':
		w.fillRectangle((board->getWidth()+1)*AMPLIFIER,4*AMPLIFIER,
			4*AMPLIFIER,1*AMPLIFIER, Xwindow::Cyan);
		break;
		case 'J':
		w.fillRectangle((board->getWidth()+1)*AMPLIFIER,3*AMPLIFIER,
			1*AMPLIFIER,1*AMPLIFIER, Xwindow::Blue);
		w.fillRectangle((board->getWidth()+1)*AMPLIFIER,4*AMPLIFIER,
			3*AMPLIFIER,1*AMPLIFIER, Xwindow::Blue);
		break;
		case 'L':
		w.fillRectangle((board->getWidth()+3)*AMPLIFIER,3*AMPLIFIER,
			1*AMPLIFIER,1*AMPLIFIER, Xwindow::Orange);
		w.fillRectangle((board->getWidth()+1)*AMPLIFIER,4*AMPLIFIER,
			3*AMPLIFIER,1*AMPLIFIER, Xwindow::Orange);
		break;
		case 'O':
		w.fillRectangle((board->getWidth()+1)*AMPLIFIER,3*AMPLIFIER,
			2*AMPLIFIER,1*AMPLIFIER, Xwindow::Yellow);
		w.fillRectangle((board->getWidth()+1)*AMPLIFIER,4*AMPLIFIER,
			2*AMPLIFIER,1*AMPLIFIER, Xwindow::Yellow);
		break;
		case 'S':
		w.fillRectangle((board->getWidth()+2)*AMPLIFIER,3*AMPLIFIER,
			2*AMPLIFIER,1*AMPLIFIER, Xwindow::Green);
		w.fillRectangle((board->getWidth()+1)*AMPLIFIER,4*AMPLIFIER,
			2*AMPLIFIER,1*AMPLIFIER, Xwindow::Green);
		break;
		case 'Z':
		w.fillRectangle((board->getWidth()+1)*AMPLIFIER,3*AMPLIFIER,
			2*AMPLIFIER,1*AMPLIFIER, Xwindow::Red);
		w.fillRectangle((board->getWidth()+2)*AMPLIFIER,4*AMPLIFIER,
			2*AMPLIFIER,1*AMPLIFIER, Xwindow::Red);
		break;
		case 'T':
		w.fillRectangle((board->getWidth()+1)*AMPLIFIER,3*AMPLIFIER,
			3*AMPLIFIER,1*AMPLIFIER, Xwindow::Magenta);
		w.fillRectangle((board->getWidth()+2)*AMPLIFIER,4*AMPLIFIER,
			1*AMPLIFIER,1*AMPLIFIER, Xwindow::Magenta);
		break;
		default:
		w.fillRectangle((board->getWidth()+1)*AMPLIFIER,3*AMPLIFIER,
			3*AMPLIFIER,2*AMPLIFIER, Xwindow::White);
		break;

	}//end switch


}
