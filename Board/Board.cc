#include "Board.h"

Board::Board(int height, int width):
height{height},width{width}
{
	for (int i = 0; i < height; ++i){
		std::vector<Cell> tempVect;
		for (int j = 0; j < width; ++j){
			tempVect.push_back(Cell{j,height - i - 1});
		}
		board.push_back(tempVect);
	}
}

int Board::getHeight(){
	return height;
}

int Board::getWidth(){
	return width;
}

Cell &Board::getCell(int x, int y){
	return board.at(height - y - 1).at(x);
}

void Board::setCell(int x, int y, char c){
	board.at(height - y - 1).at(x).setSymbol(c);
}

void Board::clearLine(int line){
	for (auto &cell : board.at(height - line - 1)){	
		cell.notifyObservers();
	}
	board.erase(board.begin() + height - line - 1);
	// create a new line on top
	std::vector<Cell> tempVect;
	for (int j = 0; j < width; ++j){
		tempVect.push_back(Cell{j,0});
	}
	board.push_back(tempVect);
	// change coordinate of cells that moved down
	int x = 0;
	int y = height - 1;
	for (auto &boardLine : board){
		x = 0;
		for (auto &cell : boardLine) {
			cell.getState().x = x;
			cell.getState().y = y;
			++x;
		}
		--y;
	}
}

bool Board::isLineFull(int line){
	for (auto cell : board.at(height - line - 1)){
		if (cell.getState().isOccupied == false){
			return false;
		}
	}
	return true;
}

void Board::clear(){
	board.clear();
	for (int i = 0; i < height; ++i){
		std::vector<Cell> tempVect;
		for (int j = 0; j < width; ++j){
			tempVect.push_back(Cell{j,height - i - 1});
		}
		board.push_back(tempVect);
	}
}

// TODO: operator<<

std::ostream &operator<<(std::ostream &out, Board &b){
	for (int i = 0; i < b.height; ++i){
		out << "|";
		for (int j = 0; j < b.width; ++j){

			Cell cell = b.getCell(j,i);
			out << cell.getState().symbol;

		}
		out << "|";
		out << std::endl;
	}
	return out;
}
