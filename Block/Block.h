#ifndef BLOCK_H
#define BLOCK_H
#include <iostream>
#include <vector>
#include "../Pattern/Subject.h"
#include "../Board/Board.h"
#include "../Pattern/Observer.h"
#include "../Board/Cell.h"


class Block:public Observer{
    virtual bool moveUpable() = 0;
    virtual bool rotatable() = 0;
    virtual bool CCrotatable() = 0;
    virtual bool moveLeft()=0;
    virtual bool moveRight()=0;
    virtual bool moveDown()=0;
protected:
    int level;
    char symbol;
    Board *gameBoard;
    std::vector<Cell *> occupiedCells;
    std::string dir;
public:
    Block(int level, char symbol, Board *gameBoard, std::vector<Cell *> occupiedCells, std::string dir= "no_dir");
    int getLevel();
    char getSymbol();
    void setSymbol(char sym);
    void notify(Subject *);
    virtual ~Block();
    void rotate();
    void rotateCC();
    void shiftLeft();
    void shiftRight();
    void shiftDown();
    void shiftUp();
    void drop();
    bool isEmpty();
};
#endif //A5_BLOCK_H
