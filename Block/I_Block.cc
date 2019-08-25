#include <iostream>
#include "I_Block.h"

using namespace std;

I_Block::I_Block(int level, char symbol, Board *gameBoard, std::vector<Cell *> occupiedCells)
        :Block::Block{level, symbol, gameBoard, occupiedCells, "horizontal"} {}


bool I_Block::moveRight() {
    if(this->dir == "horizontal"){
        int x = this->occupiedCells.back()->getState().x;
        int y = this->occupiedCells.back()->getState().y;
        for(auto p:this->occupiedCells){
            if(p->getState().x > x){
                x = p->getState().x;
            }
        }
        if (x < 0 || x+1 > 10) {
            return false;
        }
        if(this->gameBoard->getCell(x+1,y).getState().isOccupied){
            return false;
        }
    } else {
        for(auto p:this->occupiedCells){
            if (p->getState().x+1 > 10) {
                return false;
            }
            if(this->gameBoard->getCell(p->getState().x+1,p->getState().y).getState().isOccupied){
                return false;
            }
        }
    }
    return true;
}


bool I_Block::moveLeft() {
    if(this->dir == "horizontal"){
        int x = this->occupiedCells.back()->getState().x;
        int y = this->occupiedCells.back()->getState().y;
        for(auto p:this->occupiedCells){
            if(p->getState().x < x){
                x = p->getState().x;
            }
        }
        if (x-1 < 0) {
            return false;
        }
        if(this->gameBoard->getCell(x-1,y).getState().isOccupied){
            return false;
        }
    } else {
        for(auto p:this->occupiedCells){
            if (p->getState().x-1 < 0) {
                return false;
            }
            if(this->gameBoard->getCell(p->getState().x-1,p->getState().y).getState().isOccupied){
                return false;
            }
        }
    }
    return true;
}


bool I_Block::moveUpable(){
    if(this->dir == "vertical"){
        int x = this->occupiedCells.back()->getState().x;
        int y = this->occupiedCells.back()->getState().y;
        for(auto p:this->occupiedCells){
            if(p->getState().y < y){
                y = p->getState().y;
            }
        }
        if (y-1 < 0) {
            return false;
        }
        if(this->gameBoard->getCell(x,y-1).getState().isOccupied){
            return false;
        }
    } else {
        int y = this->occupiedCells.back()->getState().y;
        for(auto p:this->occupiedCells){
            if (y-1 < 0) {
                return false;
            }
            if(this->gameBoard->getCell(p->getState().x,p->getState().y-1).getState().isOccupied){
                return false;
            }
        }
    }
    return true;
}

bool I_Block::moveDown() {
    if(this->dir == "vertical"){
        int x = this->occupiedCells.back()->getState().x;
        int y = this->occupiedCells.back()->getState().y;
        for(auto p:this->occupiedCells){
            if(p->getState().y > y){
                y = p->getState().y;
            }
        }
        if (y+1 > 17) {
            return false;
        }
        if(this->gameBoard->getCell(x,y+1).getState().isOccupied){
            return false;
        }
    } else {
        int y = this->occupiedCells.back()->getState().y;
        for(auto p:this->occupiedCells){
            if (y+1 > 17) {
                return false;
            }
            if(this->gameBoard->getCell(p->getState().x,p->getState().y+1).getState().isOccupied){
                return false;
            }
        }
    }
    return true;
}


bool I_Block::rotatable() {
    int size = this->occupiedCells.size();
    if (this->dir == "horizontal") {
        int x = this->occupiedCells.back()->getState().x;
        int y = this->occupiedCells.back()->getState().y;
        for (auto p:this->occupiedCells) {
            if (p->getState().x < x) {
                x = p->getState().x;
            }
        }
        for (int i = 1; i < size; ++i) {
            if (y - i < 0 || y > 17) {
                return false;
            }
            if (this->gameBoard->getCell(x, y - i).getState().isOccupied) {
                return false;
            }
        }
        this->dir = "vertical";
    } else {
        int x = this->occupiedCells.back()->getState().x;
        int y = this->occupiedCells.back()->getState().y;
        for (auto p:this->occupiedCells) {
            if (p->getState().y > y) {
                y = p->getState().y;
            }
        }
        for (int i = 1; i < size; ++i) {
            if (x < 0 || x + i > 10) {
                return false;
            }
            if (this->gameBoard->getCell(x + i, y).getState().isOccupied) {
                return false;
            }
        }
        this->dir = "horizontal";
    }
    return true;
}


bool I_Block::CCrotatable(){
    return this->rotatable();
}
