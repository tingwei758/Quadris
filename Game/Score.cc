#include "Score.h"
#include <iomanip>

int Score::highScore = 0;

Score::Score(){
    score = 0;
}

int Score::getScore(){
    return this->score;
}

int Score::getHighScore(){
    return Score::highScore;
}

void Score::incrementScore(int num){
    score += num;
    if(score > Score::highScore){
        Score::highScore = score;
    }
}

void Score::restart(){
    score = 0;
}


std::ostream &operator<<(std::ostream &out, Score &score){
    out << "Score:";
    out << std::right << std::setw(7) << score.getScore() << std::endl;
    out << "Hi Score:";
    out << std::right << std::setw(4) << score.getHighScore() << std::endl;
    return out;
}


    


