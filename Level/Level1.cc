#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Level1.h"

using namespace std;

Level1::Level1(int num) : Level(1, num) {}

char Level1::generateNextBlock(){
    int temp = rand()%12;
    if((temp == 1) || (temp == 2)){
        return 'I';
    } else if((temp == 3) || (temp == 4)){
        return 'J';
    } else if((temp == 5) || (temp == 6)){
        return 'L';
    } else if((temp == 7) || (temp == 8)){
        return 'O';
    } else if((temp == 9) || (temp == 10)){
        return 'T';
    } else if(temp == 11){
        return 'S';
    } else {
        return 'Z';
    }
}
              
    void Level1::setSource(std::string){}
    void Level1::setRandom(bool){}

