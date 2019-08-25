#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include "Level.h"
#include "../Block/Block.h"
#include "../Block/I_Block.h"
#include "../Block/L_Block.h"
#include "../Block/J_Block.h"
#include "../Block/T_Block.h"
#include "../Block/O_Block.h"
#include "../Block/S_Block.h"
#include "../Block/Z_Block.h"
#include "../Block/special_Block.h"

using namespace std;

// Ctor: no seed provided
Level::Level(int num){
    levelval = num;
    seed = 0;
    isSeedAvailable = false;
}

// Ctor: generate on random, seed is provided
Level::Level(int num, int randomSource){
    levelval = num;
    setSeed(randomSource);
    isSeedAvailable = true;
}

// Dtor
Level::~Level(){}

// gte the level value of the Level class
int Level::getLevel(){
    return this->levelval;
}

// set the levelval to the given integer
void Level::setLevel(int num){
    levelval = num;
}

int Level::getSeed(){
    return this->seed;
}
// set the seed value to run random number to the given integer
void Level::setSeed(int num){
    seed = num;
    isSeedAvailable = true;
    srand(seed);
}

Block* Level::generateBlock(char c, Board* pb){
    if(c == 'I') {
	return generateIBlock(pb);
    } else if(c == 'J') {
        return generateJBlock(pb);
    } else if(c == 'L') {
        return generateLBlock(pb);
    } else if(c == 'O') {
        return generateOBlock(pb);
    } else if(c == 'S') {
        return generateSBlock(pb);
    } else if(c == 'T') {
        return generateTBlock(pb);
    } else if(c == 'Z') {
        return generateZBlock(pb);
    } else if(c == '*') {
        return generateSpecialBlock(pb);
    } else {
#if DEBUG
        cout << "ERROR: unexpected block character!" << endl;
#endif
        return generateIBlock(pb);
    }
}

Block* Level::generateIBlock(Board* pb){
    pb->setCell(0, 3, 'I');
    pb->setCell(1, 3, 'I');
    pb->setCell(2, 3, 'I');
    pb->setCell(3, 3, 'I');
    std::vector<Cell*> temp;
    Cell* pc1 = &(pb->getCell(0, 3));
    Cell* pc2 = &(pb->getCell(1, 3));
    Cell* pc3 = &(pb->getCell(2, 3));
    Cell* pc4 = &(pb->getCell(3, 3));
    temp.push_back(pc1);
    temp.push_back(pc2);
    temp.push_back(pc3);
    temp.push_back(pc4);
    return new I_Block(this->levelval, 'I', pb, temp);
}
Block* Level::generateJBlock(Board* pb){
    pb->setCell(0, 3, 'J');
    pb->setCell(0, 4, 'J');
    pb->setCell(1, 4, 'J');
    pb->setCell(2, 4, 'J');
    std::vector<Cell*> temp;
    Cell* pc1 = &(pb->getCell(0, 3));
    Cell* pc2 = &(pb->getCell(0, 4));
    Cell* pc3 = &(pb->getCell(1, 4));
    Cell* pc4 = &(pb->getCell(2, 4));
    temp.push_back(pc1);
    temp.push_back(pc2);
    temp.push_back(pc3);
    temp.push_back(pc4);
    return new J_Block(this->levelval, 'J', pb, temp);
}
Block* Level::generateLBlock(Board* pb){
    pb->setCell(2, 3, 'L');
    pb->setCell(2, 4, 'L');
    pb->setCell(1, 4, 'L');
    pb->setCell(0, 4, 'L');
    std::vector<Cell*> temp;
    Cell* pc1 = &(pb->getCell(2, 3));
    Cell* pc2 = &(pb->getCell(2, 4));
    Cell* pc3 = &(pb->getCell(1, 4));
    Cell* pc4 = &(pb->getCell(0, 4));
    temp.push_back(pc1);
    temp.push_back(pc2);
    temp.push_back(pc3);
    temp.push_back(pc4);
    return new L_Block(this->levelval, 'L', pb, temp);
}
Block* Level::generateOBlock(Board* pb){
    pb->setCell(0, 3, 'O');
    pb->setCell(1, 3, 'O');
    pb->setCell(0, 4, 'O');
    pb->setCell(1, 4, 'O');
    std::vector<Cell*> temp;
    Cell* pc1 = &(pb->getCell(0, 3));
    Cell* pc2 = &(pb->getCell(1, 3));
    Cell* pc3 = &(pb->getCell(0, 4));
    Cell* pc4 = &(pb->getCell(1, 4));
    temp.push_back(pc1);
    temp.push_back(pc2);
    temp.push_back(pc3);
    temp.push_back(pc4);
    return new O_Block(this->levelval, 'O', pb, temp);
}
Block* Level::generateSBlock(Board* pb){
    pb->setCell(1, 3, 'S');
    pb->setCell(2, 3, 'S');
    pb->setCell(0, 4, 'S');
    pb->setCell(1, 4, 'S');
    std::vector<Cell*> temp;
    Cell* pc1 = &(pb->getCell(1, 3));
    Cell* pc2 = &(pb->getCell(2, 3));
    Cell* pc3 = &(pb->getCell(0, 4));
    Cell* pc4 = &(pb->getCell(1, 4));
    temp.push_back(pc1);
    temp.push_back(pc2);
    temp.push_back(pc3);
    temp.push_back(pc4);
    return new S_Block(this->levelval, 'S', pb, temp);
}
Block* Level::generateZBlock(Board* pb){
    pb->setCell(0, 3, 'Z');
    pb->setCell(1, 3, 'Z');
    pb->setCell(1, 4, 'Z');
    pb->setCell(2, 4, 'Z');
    std::vector<Cell*> temp;
    Cell* pc1 = &(pb->getCell(0, 3));
    Cell* pc2 = &(pb->getCell(1, 3));
    Cell* pc3 = &(pb->getCell(1, 4));
    Cell* pc4 = &(pb->getCell(2, 4));
    temp.push_back(pc1);
    temp.push_back(pc2);
    temp.push_back(pc3);
    temp.push_back(pc4);
    return new Z_Block(this->levelval, 'Z', pb, temp);
}
Block* Level::generateTBlock(Board* pb){
    pb->setCell(0, 3, 'T');
    pb->setCell(1, 3, 'T');
    pb->setCell(2, 3, 'T');
    pb->setCell(1, 4, 'T');
    std::vector<Cell*> temp;
    Cell* pc1 = &(pb->getCell(0, 3));
    Cell* pc2 = &(pb->getCell(1, 3));
    Cell* pc3 = &(pb->getCell(2, 3));
    Cell* pc4 = &(pb->getCell(1, 4));
    temp.push_back(pc1);
    temp.push_back(pc2);
    temp.push_back(pc3);
    temp.push_back(pc4);
    return new T_Block(this->levelval, 'T', pb, temp);
}

Block* Level::generateSpecialBlock(Board* pb){
    pb->setCell(5, 3, '*');
    std::vector<Cell*> temp;
    Cell* pc1 = &(pb->getCell(5, 3));
    temp.push_back(pc1);
    return new T_Block(this->levelval, '*', pb, temp);
}

std::ostream &operator<<(std::ostream &out, Level& level){
    out << "Level:";
    out << std::right << std::setw(7) << level.getLevel() << std::endl;
    return out;
}

