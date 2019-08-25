#include "Cell.h"

Cell::Cell(int x, int y):state{CellState{x,y,' ',false}}{}

CellState &Cell::getState(){
	return state;
}

void Cell::setSymbol(char symbol){
	state.symbol = symbol;
	if (symbol == ' '){
		state.isOccupied = false;
	}
	else{
		state.isOccupied = true;
	}
}
