#include "Level2.h"


Level2::Level2(int num) : Level(2, num) {}

char Level2::generateNextBlock(){
    int temp = rand()%7;
    if(temp == 1){
        return 'I';
    } else if(temp == 2){
        return 'J';
    } else if(temp == 3){
        return 'L';
    } else if(temp == 4){
        return 'O';
    } else if(temp == 5){
        return 'T';
    } else if(temp == 6){
        return 'S';
    } else {
        return 'Z';
    }
}


    void Level2::setSource(std::string){}
    void Level2::setRandom(bool){}
