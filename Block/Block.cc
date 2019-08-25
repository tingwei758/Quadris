#include "Block.h"
#include <iostream>
#include <vector>
using namespace std;
Block::~Block() {
    for(auto &p:this->occupiedCells){
        this->gameBoard->setCell(p->getState().x, p->getState().y, ' ');
    }
}
void Block::notify(Subject *cell) {
    cell->dettach();
    vector<Cell *>temp;
    for(auto &p:this->occupiedCells){
        if(cell != p){
            temp.emplace_back(&this->gameBoard->getCell(p->getState().x, p->getState().y));
        }
    }
    this->occupiedCells.clear();
    for(auto &q: temp){
        this->occupiedCells.push_back(q);
    }
}

Block::Block(int level, char symbol,Board *gameBoard, std::vector<Cell *> occupiedCells, std::string dir):
        level{level}, symbol{symbol}, gameBoard{gameBoard}, occupiedCells{occupiedCells}, dir{dir}{}

char Block::getSymbol(){
    return this->symbol;
}

void Block::setSymbol(char sym){
    this->symbol = sym;
    for(auto p:this->occupiedCells){
      p->setSymbol(sym);
    }
}

bool ismember(Cell *r, vector<Cell *>vec){
    for(auto &s:vec){
        if((r->getState().x == s->getState().x) && (r->getState().y == s->getState().y)){
            return true;
        }
    }
    return false;
}
void Block::rotate() {
    if(this->rotatable()){
        int le_x = this->occupiedCells.back()->getState().x;
        int ri_x = this->occupiedCells.back()->getState().x;
        int low_y = this->occupiedCells.back()->getState().y;
        for(auto p:this->occupiedCells){
            if(p->getState().y > low_y) {
                low_y = p->getState().y;
            }
            if(p->getState().x < le_x){
                le_x = p->getState().x;
            }
            if(p->getState().x > ri_x){
                ri_x = p->getState().x;
            }
        }
        int move = ri_x - le_x;
        vector<Cell *>temp;
        for(auto &p:this->occupiedCells){
            this->gameBoard->setCell((le_x-(p->getState().y - low_y)),
                                     (low_y + (p->getState().x - le_x)-move),
                                     p->getState().symbol);
            temp.emplace_back(&this->gameBoard->getCell((le_x-(p->getState().y - low_y)),
                                                        (low_y + (p->getState().x - le_x)-move)));
        }
        for(auto &r: this->occupiedCells){
            if(!ismember(r, temp)){
                this->gameBoard->setCell(r->getState().x,r->getState().y,' ');
            }
        }
        this->occupiedCells.clear();
        for(auto &q: temp){
            this->occupiedCells.push_back(q);
        }
    }
}
void Block::rotateCC() {
    if(this->CCrotatable()){
        int le_x = this->occupiedCells.back()->getState().x;
        int top_y = this->occupiedCells.back()->getState().y;
        int down_y = this->occupiedCells.back()->getState().y;
        for(auto p:this->occupiedCells){
            if(p->getState().y < top_y) {
                top_y = p->getState().y;
            }
            if(p->getState().y > down_y){
                down_y = p->getState().y;
            }
            if(p->getState().x < le_x){
                le_x = p->getState().x;
            }
        }
        int move = down_y - top_y;
        vector<Cell *>temp;
        for(auto &p:this->occupiedCells){
            this->gameBoard->setCell((le_x+(p->getState().y - down_y)+move),
                                     (down_y - (p->getState().x - le_x)),
                                     p->getState().symbol);
            temp.emplace_back(&this->gameBoard->getCell((le_x+(p->getState().y - down_y)+move),
                                                        (down_y - (p->getState().x - le_x))));
        }
        for(auto &r: this->occupiedCells){
            if(!ismember(r, temp)){
                this->gameBoard->setCell(r->getState().x,r->getState().y,' ');
            }
        }
        this->occupiedCells.clear();
        for(auto &q: temp){
            this->occupiedCells.push_back(q);
        }
    }
}

void Block::shiftRight() {
    if(this->moveRight()){
        vector<Cell *>temp;
        for(auto &p: this->occupiedCells){
            this->gameBoard->setCell(p->getState().x+1,p->getState().y,p->getState().symbol);
            temp.emplace_back(&this->gameBoard->getCell(p->getState().x+1, p->getState().y));
        }
        for(auto &r: this->occupiedCells){
            if(!ismember(r, temp)){
                this->gameBoard->setCell(r->getState().x,r->getState().y,' ');
            }
        }
        this->occupiedCells.clear();
        for(auto &q: temp){
            this->occupiedCells.push_back(q);
        }
    }
}
void Block::shiftLeft() {
    if(this->moveLeft()){
        vector<Cell *>temp;
        for(auto &p: this->occupiedCells){
            this->gameBoard->setCell(p->getState().x-1,p->getState().y,p->getState().symbol);
            temp.emplace_back(&this->gameBoard->getCell(p->getState().x-1, p->getState().y));
        }
        for(auto &r: this->occupiedCells){
            if(!ismember(r, temp)){
                this->gameBoard->setCell(r->getState().x,r->getState().y,' ');
            }
        }
        this->occupiedCells.clear();
        for(auto &q: temp){
            this->occupiedCells.push_back(q);
        }
    }
}
void Block::shiftDown() {
    if(this->moveDown()){
        vector<Cell *>temp;
        for(auto &p: this->occupiedCells){
            this->gameBoard->setCell(p->getState().x,p->getState().y+1,p->getState().symbol);
            temp.emplace_back(&this->gameBoard->getCell(p->getState().x, p->getState().y+1));
        }
        for(auto &r: this->occupiedCells){
            if(!ismember(r, temp)){
                this->gameBoard->setCell(r->getState().x,r->getState().y,' ');
            }
        }
        this->occupiedCells.clear();
        for(auto &q: temp){
            this->occupiedCells.push_back(q);
        }
    }
}

void Block::shiftUp(){
    if(this->moveUpable()){
        vector<Cell *>temp;
        for(auto &p: this->occupiedCells){
            this->gameBoard->setCell(p->getState().x,p->getState().y-1,p->getState().symbol);
            temp.emplace_back(&this->gameBoard->getCell(p->getState().x, p->getState().y-1));
        }
        for(auto &r: this->occupiedCells){
            if(!ismember(r, temp)){
                this->gameBoard->setCell(r->getState().x,r->getState().y,' ');
            }
        }
        this->occupiedCells.clear();
        for(auto &q: temp){
            this->occupiedCells.push_back(q);
        }
    }
}


bool Block::isEmpty() {
    for(auto &p:this->occupiedCells){
        if(p->getState().isOccupied){
            return false;
        }
    }
    return true;
}
int Block::getLevel() {
    return this->level;
}
void Block::drop() {
    while(this->moveDown()){
        this->shiftDown();
    }
    for(auto &p: this->occupiedCells){
        p->attach(this);
    }
}
