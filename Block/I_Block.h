#ifndef I_BLOCK_H
#define I_BLOCK_H

#include <iostream>
#include <vector>
#include "Block.h"

class I_Block:public Block{
    bool moveUpable()override;
    bool rotatable() override;
    bool CCrotatable() override ;
    bool moveLeft() override ;
    bool moveRight() override ;
    bool moveDown() override ;

public:
    I_Block(int level, char symbol, Board *gameBoard, std::vector<Cell *> occupiedCells);
};
#endif //A5_I_BLOCK_H
