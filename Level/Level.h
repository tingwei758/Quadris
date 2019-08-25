#ifndef __LEVEL_H__
#define __LEVEL_H__

#include "../Block/Block.h"
#include "../Board/Board.h"
#include "../Block/I_Block.h"
#include "../Block/L_Block.h"
#include "../Block/J_Block.h"
#include "../Block/T_Block.h"
#include "../Block/O_Block.h"
#include "../Block/S_Block.h"
#include "../Block/Z_Block.h"
#include "../Block/special_Block.h"

class Block;
class Board;


class Level {
    
protected:
    bool isSeedAvailable;
    int seed;
    int levelval;
    
public:
    Level(int); // Ctor: no seed provided
    Level(int, int); // Ctor: generate on random, seed is provided
    virtual ~Level(); // Dtor
    
    
	int getLevel(); // gte the level value of the Level class
    void setLevel(int); // set the levelval to the given integer
    int getSeed();
    void setSeed(int); // set the seed value to run random number to the given integer
    virtual void setSource(std::string) = 0;
    virtual void setRandom(bool) = 0;
	virtual char generateNextBlock()=0; // pure virtual method to generate next block based on the value of the level
    Block* generateBlock(char, Board*);
    Block* generateIBlock(Board*);
    Block* generateLBlock(Board*);
    Block* generateJBlock(Board*);
    Block* generateTBlock(Board*);
    Block* generateOBlock(Board*);
    Block* generateSBlock(Board*);
    Block* generateZBlock(Board*);
    Block* generateSpecialBlock(Board*);
    friend std::ostream &operator<<(std::ostream &out, Level& level);
};

#endif

