#ifndef __LEVEL0_H__
#define __LEVEL0_H__
#include "Level.h"
#include <string>
#include <vector>

class Level0 : public Level {
    std::string source;
    std::vector<std::string> seq; // the sequence of Blocks get from the sequence.txt file
    int curr; // the position of the current Block in the sequence
public:
    ~Level0();
    Level0(int = 0, std::string = "sequence.txt"); // Ctor for Level 0
    void setSource(std::string);
    void setRandom(bool);
    char generateNextBlock(); //generate the next Block
};
#endif		

