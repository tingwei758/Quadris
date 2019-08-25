#ifndef __LEVEL1_H__
#define __LEVEL1_H__
#include "Level.h"
#include <string>
#include <vector>

class Level1 : public Level {
public:
    Level1(int);
    void setSource(std::string);
    void setRandom(bool);
    char generateNextBlock();
};              
#endif

