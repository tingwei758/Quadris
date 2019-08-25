#ifndef Z_BLOCK_H
#define Z_BLOCK_H
#include <iostream>
#include <vector>
#include "Block.h"

class Z_Block:public Block{
    bool moveUpable()override;
    bool rotatable() override;
    bool CCrotatable() override ;
    bool moveLeft() override ;
    bool moveRight() override ;
    bool moveDown() override ;
public:
    Z_Block(int level, char symbol, Board *gameBoard, std::vector<Cell *> occupiedCells);
};
#endif
