#include <iostream>
#include "O_Block.h"

using namespace std;


O_Block::O_Block(int level, char symbol, Board *gameBoard, std::vector<Cell *> occupiedCells)
        :Block{level, symbol, gameBoard, occupiedCells, "no_dir"} {}





bool O_Block::rotatable() {
    return true;
}

bool O_Block::CCrotatable() {
    return true;
}

bool O_Block::moveRight() {

    int x = this->occupiedCells.back()->getState().x;
    int top_y = this->occupiedCells.back()->getState().y;
    int low_y = this->occupiedCells.back()->getState().y;
    for(auto &p:this->occupiedCells){
        if(p->getState().x > x){
            x = p->getState().x;
        }
        if(p->getState().y > low_y){
            low_y = p->getState().y;
        }
        if(p->getState().y < top_y){
            top_y = p->getState().y;
        }
    }
    if(x < 0|| x+1 > 10){
        return false;
    }
    if(this->gameBoard->getCell(x+1, top_y).getState().isOccupied){
        return false;
    } else if(this->gameBoard->getCell(x+1, low_y).getState().isOccupied){
        return false;
    } else {
        return true;
    }

}

bool O_Block::moveLeft() {

    int x = this->occupiedCells.back()->getState().x;
    int top_y = this->occupiedCells.back()->getState().y;
    int low_y = this->occupiedCells.back()->getState().y;
    for(auto &p:this->occupiedCells){
        if(p->getState().x < x){
            x = p->getState().x;
        }
        if(p->getState().y > low_y){
            low_y = p->getState().y;
        }
        if(p->getState().y < top_y){
            top_y = p->getState().y;
        }
    }
    if(x -1  < 0|| x > 10){
        return false;
    }
    if(this->gameBoard->getCell(x-1, top_y).getState().isOccupied){
        return false;
    } else if(this->gameBoard->getCell(x-1, low_y).getState().isOccupied){
        return false;
    } else {
        return true;
    }
}


bool O_Block::moveUpable(){
    int y = this->occupiedCells.back()->getState().y;
    int le_x = this->occupiedCells.back()->getState().x;
    int ri_x = this->occupiedCells.back()->getState().x;
    for(auto &p:this->occupiedCells){
        if(p->getState().y < y){
            y = p->getState().y;
        }
        if(p->getState().x > ri_x){
            ri_x = p->getState().x;
        }
        if(p->getState().x < le_x){
            le_x = p->getState().x;
        }
    }
    if(y-1 < 0|| y > 17){
        return false;
    }
    if(this->gameBoard->getCell(ri_x, y-1).getState().isOccupied){
        return false;
    } else if(this->gameBoard->getCell(le_x, y-1).getState().isOccupied){
        return false;
    } else {
        return true;
    }
}

bool O_Block::moveDown() {
    int y = this->occupiedCells.back()->getState().y;
    int le_x = this->occupiedCells.back()->getState().x;
    int ri_x = this->occupiedCells.back()->getState().x;
    for(auto &p:this->occupiedCells){
        if(p->getState().y > y){
            y = p->getState().y;
        }
        if(p->getState().x > ri_x){
            ri_x = p->getState().x;
        }
        if(p->getState().x < le_x){
            le_x = p->getState().x;
        }
    }
    if(y < 0|| y+1 > 17){
        return false;
    }
    if(this->gameBoard->getCell(ri_x, y+1).getState().isOccupied){
        return false;
    } else if(this->gameBoard->getCell(le_x, y+1).getState().isOccupied){
        return false;
    } else {
        return true;
    }
}

