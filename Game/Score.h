#ifndef __SCORE_H__
#define __SCORE_H__

#include <iostream>

class Score {
    int score;
    static int highScore;

public:
    Score(); // Ctor

    int getScore(); // get the current score
    int getHighScore(); // get the highest score
    void incrementScore(int); // add the integer to the current score and chack if there's a new highScore
    void restart(); // reset the score when the game restart, highScore remain unchanged

    friend std::ostream &operator<<(std::ostream &out, Score &score);
};

#endif
