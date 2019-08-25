#ifndef __GAME_H__
#define __GAME_H__
#include "../Level/Level.h"
#include "../Board/Board.h"
#include "Score.h"
#include "../View/TextDisplay.h"
#include "../View/GraphicsDisplay.h"

class Game{
    std::vector<Block*> aliveBlock;
    Block* currentBlock;
    char nextBlock;
    int dropNoClear;
    Block* hintBlock;
    
public:
    Level* level;
    Score* score;
    Board* gameBoard;
    TextDisplay* td;
    GraphicsDisplay* gd;
    Game(int, int, bool);
    ~Game();
    
    void gameRestart();
    void setLevel(int);
    void hint();
    bool gameOver(char);
    void generateNextBlock();
    void generateMyBlock(char);
    void generateMyStarBlock();
    Score* getScore();
    void calculateScore();
    double calculateHintScore();
    Block* getCurrentBlock();
    char getNextBlock();
    void deleteHintBlock();
    
    void left();
    void right();
    void down();
    void clockwise();
    void counterclockwise();
    void drop();
    void levelup();
    void leveldown();
    void norandom(std::string);
    void random();
    void sequence(std::string);
    void I();
    void J();
    void L();
    void O();
    void S();
    void Z();
    void T();
    void restart();
    void seed(int);
    void scriptfile(std::string);
    void startlevel(int);
    void up();
};

#endif




