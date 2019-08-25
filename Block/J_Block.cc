#include <iostream>
#include "J_Block.h"

using namespace std;

J_Block::J_Block(int level, char symbol, Board *gameBoard, std::vector<Cell *> occupiedCells)
        :Block{level, symbol, gameBoard, occupiedCells, "h_head"} {}



bool J_Block::rotatable() {
    int x = this->occupiedCells.back()->getState().x;
    int y = this->occupiedCells.back()->getState().y;
    if(this->dir == "h_head"){
        for(auto &p:this->occupiedCells){
            if(p->getState().x < x){
                x = p->getState().x;
            }
            if(p->getState().y < y){
                y = p->getState().y;
            }
        }
        if((x < 0|| x+1 > 10)||(y-1 < 0|| y > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x, y-1).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x+1, y-1).getState().isOccupied){
            return false;
        }
        this->dir = "v_tail";
    } else if(this->dir == "v_tail"){
        for(auto &p:this->occupiedCells){
            if(p->getState().x > x){
                x = p->getState().x;
            }
            if(p->getState().y < y){
                y = p->getState().y;
            }
        }
        if((x < 0|| x+1 > 10)||(y < 0|| y+2 > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x, y+1).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x+1, y+1).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x+1, y+2).getState().isOccupied){
            return false;
        }
        this->dir = "h_tail";

    } else if(this->dir == "h_tail"){
        for(auto &p:this->occupiedCells){
            if(p->getState().x > x){
                x = p->getState().x;
            }
            if(p->getState().y > y){
                y = p->getState().y;
            }
        }
        if((x-2 < 0|| x > 10)||(y-2 < 0|| y > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x-1, y).getState().isOccupied){
            return false;
        } else if (this->gameBoard->getCell(x-2,y).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x-1, y-2).getState().isOccupied){
            return false;
        }
        this->dir = "v_head";
    } else {
        for(auto &p:this->occupiedCells){
            if(p->getState().x < x){
                x = p->getState().x;
            }
            if(p->getState().y > y){
                y = p->getState().y;
            }
        }
        if((x < 0|| x+2 > 10)||(y-1 < 0|| y > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x, y-1).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x+2,y).getState().isOccupied){
            return false;
        }
        this->dir = "h_head";
    }
    return true;
}


bool J_Block::CCrotatable() {
    int x = this->occupiedCells.back()->getState().x;
    int y = this->occupiedCells.back()->getState().y;
    if(this->dir == "h_head"){
        for(auto &p:this->occupiedCells){
            if(p->getState().x < x){
                x = p->getState().x;
            }
            if(p->getState().y < y){
                y = p->getState().y;
            }
        }
        if((x < 0|| x+1 > 10)||(y-1 < 0|| y > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x+1, y).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x+1, y-1).getState().isOccupied){
            return false;
        }
        this->dir = "v_head";
    } else if(this->dir == "v_head"){
        for(auto &p:this->occupiedCells){
            if(p->getState().x < x){
                x = p->getState().x;
            }
            if(p->getState().y > y){
                y = p->getState().y;
            }
        }
        if((x < 0|| x+2 > 10)||(y-1 < 0|| y > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x, y-1).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x+2, y-1).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x+2, y).getState().isOccupied){
            return false;
        }
        this->dir = "h_tail";

    } else if(this->dir == "h_tail"){
        for(auto &p:this->occupiedCells){
            if(p->getState().x > x){
                x = p->getState().x;
            }
            if(p->getState().y > y){
                y = p->getState().y;
            }
        }
        if((x-2 < 0|| x > 10)||(y-2 < 0|| y > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x-2, y).getState().isOccupied){
            return false;
        } else if (this->gameBoard->getCell(x-2,y-2).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x-1, y-2).getState().isOccupied){
            return false;
        }
        this->dir = "v_tail";
    } else {
        for(auto &p:this->occupiedCells){
            if(p->getState().x > x){
                x = p->getState().x;
            }
            if(p->getState().y < y){
                y = p->getState().y;
            }
        }
        if((x < 0|| x+1 > 10)||(y < 0|| y+2 > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x, y+2).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x+1,y+2).getState().isOccupied){
            return false;
        }
        this->dir = "h_head";
    }
    return true;
}


bool J_Block::moveRight() {
    int x = this->occupiedCells.back()->getState().x;
    int y = this->occupiedCells.back()->getState().y;
    if(this->dir == "h_head"){
        for(auto &p:this->occupiedCells){
            if(p->getState().x < x){
                x = p->getState().x;
            }
            if(p->getState().y < y){
                y = p->getState().y;
            }
        }
        if((x < 0|| x+3 > 10)||(y < 0|| y+1 > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x+3, y+1).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x+3, y).getState().isOccupied){
            return false;
        }
    } else if(this->dir == "v_head"){
        for(auto &p:this->occupiedCells){
            if(p->getState().x < x){
                x = p->getState().x;
            }
            if(p->getState().y > y){
                y = p->getState().y;
            }
        }
        if((x < 0|| x+2 > 10)||(y-2 < 0|| y > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x+2, y).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x+2, y-1).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x+2, y-2).getState().isOccupied){
            return false;
        }

    } else if(this->dir == "h_tail"){
        for(auto &p:this->occupiedCells){
            if(p->getState().x > x){
                x = p->getState().x;
            }
            if(p->getState().y > y){
                y = p->getState().y;
            }
        }
        if((x < 0|| x+1 > 10)||(y-1 < 0|| y > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x+1, y).getState().isOccupied){
            return false;
        } else if (this->gameBoard->getCell(x+1,y-1).getState().isOccupied){
            return false;
        }
    } else {
        for(auto &p:this->occupiedCells){
            if(p->getState().x > x){
                x = p->getState().x;
            }
            if(p->getState().y < y){
                y = p->getState().y;
            }
        }
        if((x < 0|| x+1 > 10)||(y < 0|| y+2 > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x, y+2).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x,y+1).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x+1,y).getState().isOccupied){
            return false;
        }
    }
    return true;
}

bool J_Block::moveLeft() {
    int x = this->occupiedCells.back()->getState().x;
    int y = this->occupiedCells.back()->getState().y;
    if(this->dir == "h_head"){
        for(auto &p:this->occupiedCells){
            if(p->getState().x < x){
                x = p->getState().x;
            }
            if(p->getState().y < y){
                y = p->getState().y;
            }
        }
        if((x-1 < 0|| x > 10)||(y < 0|| y+1 > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x-1, y).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x-1, y+1).getState().isOccupied){
            return false;
        }
    } else if(this->dir == "v_head"){
        for(auto &p:this->occupiedCells){
            if(p->getState().x < x){
                x = p->getState().x;
            }
            if(p->getState().y > y){
                y = p->getState().y;
            }
        }
        if((x-1 < 0|| x > 10)||(y-2 < 0|| y > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x-1, y).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x, y-1).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x, y-2).getState().isOccupied){
            return false;
        }

    } else if(this->dir == "h_tail"){
        for(auto &p:this->occupiedCells){
            if(p->getState().x > x){
                x = p->getState().x;
            }
            if(p->getState().y > y){
                y = p->getState().y;
            }
        }
        if((x-3 < 0|| x > 10)||(y-1 < 0|| y > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x-1, y).getState().isOccupied){
            return false;
        } else if (this->gameBoard->getCell(x-3,y-1).getState().isOccupied){
            return false;
        }
    } else {
        for(auto &p:this->occupiedCells){
            if(p->getState().x > x){
                x = p->getState().x;
            }
            if(p->getState().y < y){
                y = p->getState().y;
            }
        }
        if((x-2 < 0|| x > 10)||(y < 0|| y+2 > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x-2, y).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x-2,y+1).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x-2,y+2).getState().isOccupied){
            return false;
        }
    }
    return true;
}

bool J_Block::moveUpable(){
    int x = this->occupiedCells.back()->getState().x;
    int y = this->occupiedCells.back()->getState().y;
    if(this->dir == "h_head"){
        for(auto &p:this->occupiedCells){
            if(p->getState().x < x){
                x = p->getState().x;
            }
            if(p->getState().y < y){
                y = p->getState().y;
            }
        }
        if((x < 0|| x+2 > 10)||(y-1 < 0|| y > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x,y-1).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x+1,y).getState().isOccupied){
            return false;
        } else if (this->gameBoard->getCell(x+2,y).getState().isOccupied){
            return false;
        }
    } else if(this->dir == "v_head"){
        for(auto &p:this->occupiedCells){
            if(p->getState().x < x){
                x = p->getState().x;
            }
            if(p->getState().y > y){
                y = p->getState().y;
            }
        }
        if((x < 0|| x+1 > 10)||(y-3 < 0|| y > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x,y-1).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x+1, y-3).getState().isOccupied){
            return false;
        }
    } else if(this->dir == "h_tail"){
        for(auto &p:this->occupiedCells){
            if(p->getState().x > x){
                x = p->getState().x;
            }
            if(p->getState().y > y){
                y = p->getState().y;
            }
        }
        if((x-2 < 0|| x > 10)||(y-2 < 0|| y > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x-2, y-2).getState().isOccupied){
            return false;
        } else if (this->gameBoard->getCell(x-1,y-2).getState().isOccupied){
            return false;
        } else if (this->gameBoard->getCell(x,y-2).getState().isOccupied){
            return false;
        }
    } else {
        for(auto &p:this->occupiedCells){
            if(p->getState().x > x){
                x = p->getState().x;
            }
            if(p->getState().y < y){
                y = p->getState().y;
            }
        }
        if((x-1 < 0|| x > 10)||(y-1 < 0|| y > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x, y-1).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x-1,y-1).getState().isOccupied){
            return false;
        }
    }
    return true;
}
bool J_Block::moveDown() {
    int x = this->occupiedCells.back()->getState().x;
    int y = this->occupiedCells.back()->getState().y;
    if(this->dir == "h_head"){
        for(auto &p:this->occupiedCells){
            if(p->getState().x < x){
                x = p->getState().x;
            }
            if(p->getState().y < y){
                y = p->getState().y;
            }
        }
        if((x < 0|| x+2 > 10)||(y < 0|| y+2 > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x,y+2).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x+1,y+2).getState().isOccupied){
            return false;
        } else if (this->gameBoard->getCell(x+2,y+2).getState().isOccupied){
            return false;
        }
    } else if(this->dir == "v_head"){
        for(auto &p:this->occupiedCells){
            if(p->getState().x < x){
                x = p->getState().x;
            }
            if(p->getState().y > y){
                y = p->getState().y;
            }
        }
        if((x < 0|| x+1 > 10)||(y < 0|| y+1 > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x,y+1).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x+1, y+1).getState().isOccupied){
            return false;
        }
    } else if(this->dir == "h_tail"){
        for(auto &p:this->occupiedCells){
            if(p->getState().x > x){
                x = p->getState().x;
            }
            if(p->getState().y > y){
                y = p->getState().y;
            }
        }
        if((x-2 < 0|| x > 10)||(y < 0|| y+1 > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x-2, y).getState().isOccupied){
            return false;
        } else if (this->gameBoard->getCell(x-1,y).getState().isOccupied){
            return false;
        } else if (this->gameBoard->getCell(x,y+1).getState().isOccupied){
            return false;
        }
    } else {
        for(auto &p:this->occupiedCells){
            if(p->getState().x > x){
                x = p->getState().x;
            }
            if(p->getState().y < y){
                y = p->getState().y;
            }
        }
        if((x-1 < 0|| x > 10)||(y < 0|| y+3 > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x, y+1).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x-1,y+3).getState().isOccupied){
            return false;
        }
    }
    return true;
}







