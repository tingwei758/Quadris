#ifndef __LEVEL3_H__
#define __LEVEL3_H__
#include "Level.h"
#include <string>
#include <vector>

class Level3 : public Level {
    bool random;
    std::string source;
    std::vector<std::string> seq; // the sequence of Blocks get from the sequence.txt file
    int curr; // the position of the current Block in the sequence
public:
    Level3(int, bool = true, std::string = "sequence.txt");
    void setSource(std::string);
    void setRandom(bool);
    char generateNextBlock();
    char randomGenerate();
    char fileGenerate();
};
#endif




