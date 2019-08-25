#include "Level3.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

Level3::Level3(int num, bool r, string str) : Level(3, num) {
    this->random = r;
    curr = 0;
    source = str;
    ifstream filestream;
    filestream.open(source);
    if(!filestream) return;
    string s;
    filestream >> s;
    while (!filestream.eof()) {
      seq.push_back(s);
      filestream >> s;
  }
  filestream.close();
}

void Level3::setSource(string str){
    this->random = false;
    seq.clear();
    curr = 0;
    source = str;
    ifstream filestream;
    filestream.open(source);
    if(!filestream) return;
    string s;
    filestream >> s;
    while (!filestream.eof()) {
      seq.push_back(s);
      filestream >> s;
  }
  filestream.close();
}
void Level3::setRandom(bool r){
    this->random = r;
}

char Level3::generateNextBlock(){
    if(this->random == true){
        return randomGenerate();
    } else {
        return fileGenerate();
    }
}

char Level3::randomGenerate(){
    int temp = rand()%9;
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
    } else if((temp == 6) || (temp == 7)){
        return 'S';
    } else {
        return 'Z';
    }
}

char Level3::fileGenerate(){
    int prior = curr;
    curr = (curr + 1) % seq.size();
    return seq[prior][0];
}



