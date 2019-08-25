#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Level0.h"
#include <iostream>

using namespace std;

Level0::~Level0(){}

Level0::Level0(int seed, string str): Level(0, seed) {
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

char Level0::generateNextBlock(){
    int prior = curr;
    curr = (curr+1)%seq.size();
    return seq[prior][0];
}

void Level0::setSource(std::string str){
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
void Level0::setRandom(bool){}

