
#ifndef SPECIAL_BLOCK_H
#define SPECIAL_BLOCK_H

#include <iostream>
#include <vector>
#include "Block.h"

class special_Block:public Block{
    bool rotatable() override;
    bool CCrotatable() override ;
    bool moveLeft() override ;
    bool moveRight() override ;
    bool moveDown() override ;
public:
    special_Block(int level, char symbol, Board *gameBoard, std::vector<Cell *> occupiedCells);
};
#endif


