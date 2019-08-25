#include <iostream>
#include "T_Block.h"

using namespace std;



T_Block::T_Block(int level, char symbol, Board *gameBoard, std::vector<Cell *> occupiedCells)
        :Block{level, symbol, gameBoard, occupiedCells, "down"} {}




bool T_Block::rotatable() {
    int x = this->occupiedCells.back()->getState().x;
    int y = this->occupiedCells.back()->getState().y;
    if(this->dir == "down"){
        for(auto &p:this->occupiedCells){
            if(p->getState().y > y){
                x = p->getState().x;
                y = p->getState().y;
            }
        }
        if((x < 0|| x > 10)||(y-2 < 0|| y > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x,y-2).getState().isOccupied){
            return false;
        }
        this->dir = "left";
    } else if(this->dir == "left"){
        for(auto &p:this->occupiedCells){
            if(p->getState().x < x){
                x = p->getState().x;
                y = p->getState().y;
            }
        }
        if((x < 0|| x+2 > 10)||(y < 0|| y+1 > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x,y+1).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x+2,y+1).getState().isOccupied){
            return false;
        }
        this->dir = "up";
    } else if(this->dir == "up"){
        for(auto &p:this->occupiedCells){
            if(p->getState().y < y){
                x = p->getState().x;
                y = p->getState().y;
            }
        }
        if((x < 0|| x+1 > 10)||(y-1 < 0|| y > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x,y-1).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x+1,y).getState().isOccupied){
            return false;
        }
        this->dir = "right";
    } else {
        for(auto &p:this->occupiedCells){
            if(p->getState().x > x){
                x = p->getState().x;
                y = p->getState().y;
            }
        }
        if((x < 0|| x+1 > 10)||(y < 0|| y+1 > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x,y+1).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x+1,y).getState().isOccupied){
            return false;
        }
        this->dir = "down";
    }
    return true;
}



bool T_Block::CCrotatable() {
    int x = this->occupiedCells.back()->getState().x;
    int y = this->occupiedCells.back()->getState().y;
    if(this->dir == "down"){
        for(auto &p:this->occupiedCells){
            if(p->getState().y > y){
                x = p->getState().x;
                y = p->getState().y;
            }
        }
        if((x-1 < 0|| x > 10)||(y-2 < 0|| y > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x-1,y-2).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x-1,y).getState().isOccupied){
            return false;
        }
        this->dir = "right";
    } else if(this->dir == "right"){
        for(auto &p:this->occupiedCells){
            if(p->getState().x > x){
                x = p->getState().x;
                y = p->getState().y;
            }
        }
        if((x < 0|| x+1 > 10)||(y < 0|| y+1 > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x,y+1).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x+1,y+1).getState().isOccupied){
            return false;
        }
        this->dir = "up";
    } else if(this->dir == "up"){
        for(auto &p:this->occupiedCells){
            if(p->getState().y < y){
                x = p->getState().x;
                y = p->getState().y;
            }
        }
        if((x-1 < 0|| x > 10)||(y-1 < 0|| y > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x,y-1).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x-1,y).getState().isOccupied){
            return false;
        }
        this->dir = "left";
    } else {
        for(auto &p:this->occupiedCells){
            if(p->getState().x < x){
                x = p->getState().x;
                y = p->getState().y;
            }
        }
        if((x < 0|| x+2 > 10)||(y < 0|| y > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x+2,y).getState().isOccupied){
            return false;
        }
        this->dir = "down";
    }
    return true;
}


bool T_Block::moveRight() {
    int x = this->occupiedCells.back()->getState().x;
    int y = this->occupiedCells.back()->getState().y;
    if(this->dir == "down"){
        for(auto &p:this->occupiedCells){
            if(p->getState().y > y){
                x = p->getState().x;
                y = p->getState().y;
            }
        }
        if((x < 0|| x+2 > 10)||(y-1 < 0|| y > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x+1,y).getState().isOccupied){
            return false;
        } else if (this->gameBoard->getCell(x+2,y-1).getState().isOccupied){
            return false;
        }
    } else if(this->dir == "left"){
        for(auto &p:this->occupiedCells){
            if(p->getState().x < x){
                x = p->getState().x;
                y = p->getState().y;
            }
        }
        if((x < 0|| x+2 > 10)||(y-1 < 0|| y+1 > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x+2,y+1).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x+2,y-1).getState().isOccupied){
            return false;
        } else if (this->gameBoard->getCell(x+2,y).getState().isOccupied){
            return false;
        }
    } else if(this->dir == "up"){
        for(auto &p:this->occupiedCells){
            if(p->getState().y < y){
                x = p->getState().x;
                y = p->getState().y;
            }
        }
        if((x < 0|| x+2 > 10)||(y < 0|| y+1 > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x+1,y).getState().isOccupied){
            return false;
        } else if (this->gameBoard->getCell(x+2,y+1).getState().isOccupied){
            return false;
        }
    } else {
        for(auto &p:this->occupiedCells){
            if(p->getState().x > x){
                x = p->getState().x;
                y = p->getState().y;
            }
        }
        if((x < 0|| x+1 > 10)||(y-1 < 0|| y+1 > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x,y+1).getState().isOccupied){
            return false;
        } else if (this->gameBoard->getCell(x,y-1).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x+1,y).getState().isOccupied){
            return false;
        }
    }
    return true;
}


bool T_Block::moveLeft() {
    int x = this->occupiedCells.back()->getState().x;
    int y = this->occupiedCells.back()->getState().y;
    if(this->dir == "down"){
        for(auto &p:this->occupiedCells){
            if(p->getState().y > y){
                x = p->getState().x;
                y = p->getState().y;
            }
        }
        if((x-2 < 0|| x > 10)||(y-1 < 0|| y > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x-1,y).getState().isOccupied){
            return false;
        } else if (this->gameBoard->getCell(x-2,y-1).getState().isOccupied){
            return false;
        }
    } else if(this->dir == "left"){
        for(auto &p:this->occupiedCells){
            if(p->getState().x < x){
                x = p->getState().x;
                y = p->getState().y;
            }
        }
        if((x-1 < 0|| x > 10)||(y-1 < 0|| y+1 > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x,y+1).getState().isOccupied){
            return false;
        } else if (this->gameBoard->getCell(x,y-1).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x-1,y).getState().isOccupied){
            return false;
        }
    } else if(this->dir == "up"){
        for(auto &p:this->occupiedCells){
            if(p->getState().y < y){
                x = p->getState().x;
                y = p->getState().y;
            }
        }
        if((x-2 < 0|| x > 10)||(y < 0|| y+1 > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x-1,y).getState().isOccupied){
            return false;
        } else if (this->gameBoard->getCell(x-2,y+1).getState().isOccupied){
            return false;
        }
    } else {
        for(auto &p:this->occupiedCells){
            if(p->getState().x > x){
                x = p->getState().x;
                y = p->getState().y;
            }
        }
        if((x-2 < 0|| x > 10)||(y-1 < 0|| y+1 > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x-2,y+1).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x-2,y-1).getState().isOccupied){
            return false;
        } else if (this->gameBoard->getCell(x-2,y).getState().isOccupied){
            return false;
        }
    }
    return true;
}

bool T_Block::moveUpable(){
    int x = this->occupiedCells.back()->getState().x;
    int y = this->occupiedCells.back()->getState().y;
    if(this->dir == "down"){
        for(auto &p:this->occupiedCells){
            if(p->getState().y > y){
                x = p->getState().x;
                y = p->getState().y;
            }
        }
        if((x-1 < 0|| x+1 > 10)||(y-2 < 0|| y > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x,y-2).getState().isOccupied){
            return false;
        } else if (this->gameBoard->getCell(x+1,y-2).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x-1,y-2).getState().isOccupied){
            return false;
        }
    } else if(this->dir == "left"){
        for(auto &p:this->occupiedCells){
            if(p->getState().x < x){
                x = p->getState().x;
                y = p->getState().y;
            }
        }
        if((x < 0|| x+1 > 10)||(y-2 < 0|| y > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x,y-1).getState().isOccupied){
            return false;
        } else if (this->gameBoard->getCell(x+1,y-2).getState().isOccupied){
            return false;
        }

    } else if(this->dir == "up"){
        for(auto &p:this->occupiedCells){
            if(p->getState().y < y){
                x = p->getState().x;
                y = p->getState().y;
            }
        }
        if((x-1 < 0|| x+1 > 10)||(y-1 < 0|| y > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x+1,y).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x,y-1).getState().isOccupied){
            return false;
        } else if (this->gameBoard->getCell(x-1,y).getState().isOccupied){
            return false;
        }
    } else {
        for(auto &p:this->occupiedCells){
            if(p->getState().x > x){
                x = p->getState().x;
                y = p->getState().y;
            }
        }
        if((x-1 < 0|| x > 10)||(y-2 < 0|| y > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x-1,y-2).getState().isOccupied){
            return false;
        } else if (this->gameBoard->getCell(x,y-1).getState().isOccupied){
            return false;
        }
    }
    return true;
}

bool T_Block::moveDown() {
    int x = this->occupiedCells.back()->getState().x;
    int y = this->occupiedCells.back()->getState().y;
    if(this->dir == "down"){
        for(auto &p:this->occupiedCells){
            if(p->getState().y > y){
                x = p->getState().x;
                y = p->getState().y;
            }
        }
        if((x-1 < 0|| x+1 > 10)||(y < 0|| y+1 > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x,y+1).getState().isOccupied){
            return false;
        } else if (this->gameBoard->getCell(x+1,y).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x-1,y).getState().isOccupied){
            return false;
        }
    } else if(this->dir == "left"){
        for(auto &p:this->occupiedCells){
            if(p->getState().x < x){
                x = p->getState().x;
                y = p->getState().y;
            }
        }
        if((x < 0|| x+1 > 10)||(y < 0|| y+2 > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x,y+1).getState().isOccupied){
            return false;
        } else if (this->gameBoard->getCell(x+1,y+2).getState().isOccupied){
            return false;
        }

    } else if(this->dir == "up"){
        for(auto &p:this->occupiedCells){
            if(p->getState().y < y){
                x = p->getState().x;
                y = p->getState().y;
            }
        }
        if((x-1 < 0|| x+1 > 10)||(y < 0|| y+2 > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x-1,y+2).getState().isOccupied){
            return false;
        } else if(this->gameBoard->getCell(x,y+2).getState().isOccupied){
            return false;
        } else if (this->gameBoard->getCell(x+1,y+2).getState().isOccupied){
            return false;
        }
    } else {
        for(auto &p:this->occupiedCells){
            if(p->getState().x > x){
                x = p->getState().x;
                y = p->getState().y;
            }
        }
        if((x-1 < 0|| x > 10)||(y < 0|| y+2 > 17)){
            return false;
        }
        if(this->gameBoard->getCell(x-1,y+2).getState().isOccupied){
            return false;
        } else if (this->gameBoard->getCell(x,y+1).getState().isOccupied){
            return false;
        }
    }
    return true;
}
