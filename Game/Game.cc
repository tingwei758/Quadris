#include <iterator>
#include <iostream>
#include <vector>
#include "Game.h"
#include "../Level/Level0.h"
#include "../Level/Level1.h"
#include "../Level/Level2.h"
#include "../Level/Level3.h"
#include "../Level/Level4.h"

using namespace std;

Game::Game(int l, int s, bool graph){
    score = new Score();
    if(l == 1){
        level = new Level1(s);
    } else if(l == 2){
        level = new Level2(s);
    } else if(l == 3){
        level = new Level3(s);
    } else if(l == 4){
        level = new Level4(s);
    } else {
        level = new Level0(s);
    }
    gameBoard = new Board(18, 11);
    hintBlock = nullptr;
    nextBlock = level->generateNextBlock();
    currentBlock = level->generateBlock(nextBlock, gameBoard);
    aliveBlock.push_back(currentBlock);
    nextBlock = level->generateNextBlock();
    td = new TextDisplay(gameBoard, score, &level, &nextBlock);
    if(graph){
        gd = new GraphicsDisplay(gameBoard, score, &level, &nextBlock);
    } else {
        gd = nullptr;
    }
    dropNoClear = 0;
}


Game::~Game(){
    int size = aliveBlock.size();
    for(int i = 0; i < size; i++){
        Block* temp = aliveBlock[i];
        delete temp;
    }

    if(score != nullptr) delete score;
    if(gameBoard != nullptr) delete gameBoard;
    if(hintBlock != nullptr) delete hintBlock;
    aliveBlock.clear();
    if(level != nullptr) delete level;
    if(td != nullptr) delete td;
    if(gd != nullptr) delete gd;
}


void Game::gameRestart(){;
    score->restart();
    for(auto &p:this->aliveBlock){
      delete p;
  }
  gameBoard->clear();
  aliveBlock.clear();
  nextBlock = level->generateNextBlock();
  if(hintBlock != nullptr) delete hintBlock;
  hintBlock = nullptr;
  currentBlock = level->generateBlock(nextBlock, gameBoard);
  aliveBlock.push_back(currentBlock);
  nextBlock = level->generateNextBlock();
  dropNoClear = 0;
}


void Game::setLevel(int num){
    level->setLevel(num);
    int s = level->getSeed();
    delete level;
    if(num == 1){
        level = new Level1(s);
    } else if(num == 2){
        level = new Level2(s);
    } else if(num == 3){
        level = new Level3(s);
    } else if(num == 4){
        level = new Level4(s);
    } else {
        level = new Level0(s);
    }
}


bool Game::gameOver(char next){
    if(next == 'I'){
        if(gameBoard->getCell(0, 3).getState().isOccupied) return true;
        if(gameBoard->getCell(1, 3).getState().isOccupied) return true;
        if(gameBoard->getCell(2, 3).getState().isOccupied) return true;
        if(gameBoard->getCell(3, 3).getState().isOccupied) return true;
    }else if(next == 'J'){
        if(gameBoard->getCell(0, 3).getState().isOccupied) return true;
        if(gameBoard->getCell(0, 4).getState().isOccupied) return true;
        if(gameBoard->getCell(1, 4).getState().isOccupied) return true;
        if(gameBoard->getCell(2, 4).getState().isOccupied) return true;
    }else if(next == 'L'){
        if(gameBoard->getCell(2, 3).getState().isOccupied) return true;
        if(gameBoard->getCell(2, 4).getState().isOccupied) return true;
        if(gameBoard->getCell(1, 4).getState().isOccupied) return true;
        if(gameBoard->getCell(0, 4).getState().isOccupied) return true;
    }else if(next == 'O'){
        if(gameBoard->getCell(0, 3).getState().isOccupied) return true;
        if(gameBoard->getCell(1, 3).getState().isOccupied) return true;
        if(gameBoard->getCell(0, 4).getState().isOccupied) return true;
        if(gameBoard->getCell(1, 4).getState().isOccupied) return true;
    }else if(next == 'S'){
        if(gameBoard->getCell(1, 3).getState().isOccupied) return true;
        if(gameBoard->getCell(2, 3).getState().isOccupied) return true;
        if(gameBoard->getCell(0, 4).getState().isOccupied) return true;
        if(gameBoard->getCell(1, 4).getState().isOccupied) return true;
    }else if(next == 'Z'){
        if(gameBoard->getCell(0, 3).getState().isOccupied) return true;
        if(gameBoard->getCell(1, 3).getState().isOccupied) return true;
        if(gameBoard->getCell(1, 4).getState().isOccupied) return true;
        if(gameBoard->getCell(2, 4).getState().isOccupied) return true;
    }else if(next == 'T'){
        if(gameBoard->getCell(0, 3).getState().isOccupied) return true;
        if(gameBoard->getCell(1, 3).getState().isOccupied) return true;
        if(gameBoard->getCell(2, 3).getState().isOccupied) return true;
        if(gameBoard->getCell(1, 4).getState().isOccupied) return true;
    }else if(next == '*'){
        if(gameBoard->getCell(5, 3).getState().isOccupied) return true;
    }return false;
}

void Game::generateNextBlock(){
    if(gameOver(nextBlock)){
        cout << "Game Over" <<endl;
        gameRestart();
        return;
    }
    currentBlock = level->generateBlock(nextBlock, gameBoard);
    aliveBlock.push_back(currentBlock);
    nextBlock = level->generateNextBlock();
}

void Game::generateMyBlock(char c){
    delete currentBlock;
    aliveBlock.pop_back();
    if(gameOver(c)){
        cout << "Game Over" <<endl;
        gameRestart();
        return;
    }
    currentBlock = level->generateBlock(c, gameBoard);
    aliveBlock.push_back(currentBlock);
}

void Game::generateMyStarBlock(){
    if(gameOver('*')){
        cout << "Game Over" <<endl;
        gameRestart();
        return;
    }
    Block* temp = currentBlock;
    currentBlock = level->generateBlock('*', gameBoard);
    aliveBlock.push_back(currentBlock);
    currentBlock->drop();
    calculateScore();
    currentBlock = temp;
}

Score* Game::getScore(){
    return this->score;
}

void Game::calculateScore(){
    int old = score->getScore();
    int full = 0;
    for(int i = 3; i < 18; i++){
        if(gameBoard->isLineFull(i)){
            full++;
            gameBoard->clearLine(i);
            dropNoClear = 0;
        }
    }
    if(full>0){
        score->incrementScore((level->getLevel()+full)*(level->getLevel()+full));
    }
    for(vector<Block*>::iterator it = aliveBlock.begin(); it != aliveBlock.end();){
        Block* temp = *it;
        if(temp->isEmpty()){
            score->incrementScore((temp->getLevel()+1)*(temp->getLevel()+1));
            delete temp;
            it = aliveBlock.erase(it);
        } else {
            it++;
        }
    }
    if(score->getScore() == old){
        this->dropNoClear++;
    }
    if(((dropNoClear % 5) == 0) && (this->level->getLevel() == 4)){
        generateMyStarBlock();
    }
}


Block* Game::getCurrentBlock(){
    return this->currentBlock;
}

char Game::getNextBlock(){
    return this->nextBlock;
}


void Game::hint(){
    char old = currentBlock->getSymbol();
    double hi = -999999999.0;
    int rem = 0;
    delete currentBlock;
    currentBlock = nullptr;
    aliveBlock.pop_back();
    for(int i = 0; i < 44; i++){
        hintBlock = level->generateBlock(old, gameBoard);
        hintBlock->setSymbol('?');
        double addscore = 0;
        int rotatenum = i / 11 ;
        int rightnum = i % 11;
        for(int j = 0; j < rotatenum; j++){
            hintBlock->rotate();
        }
        for(int k = 0; k < rightnum; k++){
            hintBlock->shiftRight();
        }
        hintBlock->drop();
        addscore = calculateHintScore();
        if(addscore > hi){
            hi = addscore;
            rem = i;
        }
        delete hintBlock;
        hintBlock = nullptr;
    }
    for(int i = 0; i < 44 ; i++){
        hintBlock = level->generateBlock(old, gameBoard);
        hintBlock->setSymbol('?');
        int rotatenum = i / 11 ;
        int rightnum = i % 11;
        for(int j = 0; j < rotatenum; j++){
            hintBlock->rotate();
        }
        for(int k = 0; k < rightnum; k++){
            hintBlock->shiftRight();
        }
        hintBlock->drop();        
        if(i == rem){
            break;
        } else {
            delete hintBlock;
            hintBlock = nullptr;
        }
    }
    if(gameOver(old)){
        cout << "No more hint" <<endl;
        delete hintBlock;
        hintBlock = nullptr;
        currentBlock = level->generateBlock(old, gameBoard);
        aliveBlock.push_back(currentBlock);
    }
    currentBlock = level->generateBlock(old, gameBoard);
    aliveBlock.push_back(currentBlock);
}

double Game::calculateHintScore(){
    double heights[11] = {0};
    double numOfClears = 0;
    double numOfHoles = 0;
    double sumOfHeight = 0;
    double bumpiness = 0;
    for(int i = 3; i < 18; i++){
        if(gameBoard->isLineFull(i)){
            numOfClears++;
        }
    }
    for (int j = 0; j < 11; ++j){
        for (int i = 3; i < 18;++i){
            if (gameBoard->getCell(j,i).getState().isOccupied){
                heights[j] = double(18 - i);
                sumOfHeight += double(18 - i);
                break;
            }
        }
    }
    for (int i = 4; i < 18;++i){
        for (int j = 0; j < 11; ++j){
            if ((!gameBoard->getCell(j,i).getState().isOccupied) &&(!gameBoard->getCell(j,i-1).getState().isOccupied)){
                numOfHoles++;
            }
        }
    }
    double meanHeight = (double)sumOfHeight/(double)11;
    for (int k = 0; k < 11; ++k){
        double difference = heights[k] - meanHeight;
        difference = (difference > 0 ? difference : -difference);
        bumpiness += difference;
    }
    return sumOfHeight*-0.510066 + numOfClears*0.760666 + numOfHoles*-0.35663 + bumpiness*-0.184483;
}

void Game::deleteHintBlock(){
    if (hintBlock){
        delete hintBlock;
        hintBlock = nullptr;
    }
}

void Game::left(){
    currentBlock->shiftLeft();
    if(this->currentBlock->getLevel() == 3){
     currentBlock->shiftDown();
 }
}

void Game::right(){
    currentBlock->shiftRight();
    if(this->currentBlock->getLevel() == 3){
        currentBlock->shiftDown();
    }
}

void Game::down(){
    currentBlock->shiftDown();
}

void Game::clockwise(){
    currentBlock->rotate();
    if(this->currentBlock->getLevel() == 3){
        currentBlock->shiftDown();
    }
}

void Game::counterclockwise(){
    currentBlock->rotateCC();
    if(this->currentBlock->getLevel() == 3){
        currentBlock->shiftDown();
    }
}

void Game::drop(){
    currentBlock->drop();
    calculateScore();
    generateNextBlock();
}

void Game::levelup(){
    int newlevel = this->level->getLevel() + 1;
    if(newlevel == 5){
        return;
    }
    setLevel(newlevel);
}

void Game::leveldown(){
    int newlevel = this->level->getLevel() - 1;
    if(newlevel == -1){
        return;
    }
    setLevel(newlevel);
}

void Game::norandom(std::string str){
    int currlevel = this->level->getLevel();
    if((currlevel != 3) && (currlevel != 4)){
        return;
    }
    level->setSource(str);
}

void Game::random(){
    level->setRandom(true);
}

void Game::sequence(std::string){}

void Game::I(){
    generateMyBlock('I');
}

void Game::J(){
    generateMyBlock('J');
}

void Game::L(){
    generateMyBlock('L');
}

void Game::O(){
    generateMyBlock('O');
}

void Game::S(){
    generateMyBlock('S');
}

void Game::Z(){
    generateMyBlock('Z');
}

void Game::T(){
    generateMyBlock('T');
}

void Game::restart(){
    gameRestart();
}

void Game::scriptfile(std::string str){
    int currlevel = this->level->getLevel();
    if(currlevel != 0){
        return;
    }
    level->setSource(str);
    delete currentBlock;
    aliveBlock.pop_back();
    nextBlock = level->generateNextBlock();
    currentBlock = level->generateBlock(nextBlock, gameBoard);
    aliveBlock.push_back(currentBlock);
    nextBlock = level->generateNextBlock();
}

void Game::up(){
    currentBlock->shiftUp();
}


