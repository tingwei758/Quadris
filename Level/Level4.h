#ifndef __LEVEL4_H__
#define __LEVEL4_H__
#include "Level.h"
#include <string>
#include <vector>

class Level4 : public Level {
    bool random;
    std::string source;
    std::vector<std::string> seq; // the sequence of Blocks get from the sequence.txt file
    int curr; // the position of the current Block in the sequence
public:
    Level4(int, bool = true, std::string = "sequence.txt");
    void setSource(std::string);
    void setRandom(bool);
    char generateNextBlock();
    char randomGenerate();
    char fileGenerate();
};
#endif




