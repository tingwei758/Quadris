#ifndef __LEVEL2_H__
#define __LEVEL2_H__
#include "Level.h"
#include <string>
#include <vector>

class Level2 : public Level {
public:
    Level2(int);
    void setSource(std::string);
    void setRandom(bool);
    char generateNextBlock();
};
#endif


