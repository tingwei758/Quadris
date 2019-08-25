#ifndef S_BLOCK_H
#define S_BLOCK_H
#include <iostream>
#include <vector>
#include "Block.h"

class S_Block:public Block{
    bool moveUpable()override;    
    bool rotatable() override;
    bool CCrotatable() override ;
    bool moveLeft() override ;
    bool moveRight() override ;
    bool moveDown() override ;
public:
    S_Block(int level, char symbol, Board *gameBoard, std::vector<Cell *> occupiedCells);
};
#endif
