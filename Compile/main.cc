#include "../Game/Game.h"
#include "../View/TextDisplay.h"
#include "../View/GraphicsDisplay.h"
#include "../Pattern/Invoker.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <time.h>
#include <cctype>

#include "../Command/Left.h"
#include "../Command/Right.h"
#include "../Command/Down.h"
#include "../Command/Up.h"
#include "../Command/Clockwise.h"
#include "../Command/Counterclockwise.h"
#include "../Command/Drop.h"
#include "../Command/Levelup.h"
#include "../Command/Leveldown.h"
#include "../Command/NoRandom.h"
#include "../Command/Random.h"
#include "../Command/I_Command.h"
#include "../Command/J_Command.h"
#include "../Command/L_Command.h"
#include "../Command/O_Command.h"
#include "../Command/S_Command.h"
#include "../Command/Z_Command.h"
#include "../Command/T_Command.h"
#include "../Command/Restart.h"
#include "../Command/Hint.h"

using namespace std;

// Do not remove any code; do not add code other than where indicated.

int main(int argc, char *argv[]) {
  cin.exceptions(ios::eofbit|ios::failbit);

  int seed = static_cast<int>(time(0));
  int startlevel = 0;
  string filename = "sequence.txt";
  bool hasgraph = true;

  for (int i = 1; i < argc; ++i) {
    if (argv[i] == string{"-seed"}) {
      if (i + 1 >= argc || ! (istringstream{argv[i + 1]} >> seed)) {
        cerr << "Usage: program [-seed xxx] [-scriptfile filename] [-startlevel [1|2|3|4]]" << endl;
        return 1;
      }
      ++i; // skip the next args
    }
    else if (argv[i] == string{"-scriptfile"}) {
      if (i + 1 >= argc || ! (istringstream{argv[i + 1]} >> filename)) {
        cerr << "Usage: program [-seed xxx] [-scriptfile filename] [-startlevel [1|2|3|4]]" << endl;
        return 1;
      }
      ++i; // skip the next args
    }
    else if (argv[i] == string{"-startlevel"}) {
      if (i + 1 >= argc || ! (istringstream{argv[i + 1]} >> startlevel)) {
        cerr << "Usage: program [-seed xxx] [-scriptfile filename] [-startlevel [1|2|3|4]]" << endl;
        return 1;
      }
      if (startlevel < 0 || startlevel > 4){
        startlevel = 0;
      }
      ++i; // skip the next args
    }
    else if (argv[i] == string{"-text"}) {
      hasgraph = false;
    }
    else {
      cerr << "Usage: program [-seed xxx] [-scriptfile filename] [-startlevel [1|2|3|4]]" << endl;
      return 1;
    }
  }


  Game *myGame = new Game{startlevel,seed,hasgraph};
  myGame->scriptfile(filename); 
  Invoker invoker;
  string input;

  const string available_cmd[] = {"left","right","down","clockwise","counterclockwise","drop",
  "levelup","leveldown","norandom","random","sequence",
  "I","J","L","O","S","Z","T","restart","hint", "up"};

  cout << *(myGame->td);
  if (hasgraph){
    myGame->gd->displayBoard();
  }

  ifstream filestream;
  bool readFromFile = false;

  try {
    while (true) {
      if (readFromFile){
        filestream >> input;
        if (filestream.eof()){
          readFromFile = false;
          filestream.close();
          continue;
        }
      }
      else{
        if (!(cin >> input)) break;
      }

      int multiplier = 1;
      int digit = 0;
      string cmd;

      for (unsigned int i = 0; i < input.size(); ++i){
        if (isdigit(input[i])){
          digit++;
        }
        else{
          cmd = input.substr(i);
          break;
        }
      }

      if (digit > 0){
        istringstream ss{input};
        ss >> multiplier;
      }

      // try auto-completion
      vector <string> temp;
      for(auto c : available_cmd){
        if (c.substr(0,cmd.size()) == cmd){
          temp.push_back(c);
        }
      }
      if (temp.size() == 1){
        cmd = temp.front();
      }
      temp.clear();


      // do command
      if (cmd == "left") {
        Left command{myGame};
        invoker.setCommand(&command);
        while(multiplier > 0){
          invoker.action();
          multiplier--;
        }
        cout << *(myGame->td);
        if (hasgraph){
          myGame->gd->displayBoard();
        }      
      }

      else if (cmd == "right") {
        Right command{myGame};
        invoker.setCommand(&command);
        while(multiplier > 0){
          invoker.action();
          multiplier--;
        }
        cout << *(myGame->td);
        if (hasgraph){
          myGame->gd->displayBoard();
        }      
      } else if (cmd == "up") {
        Up command{myGame};
        invoker.setCommand(&command);
        while(multiplier > 0){
          invoker.action();
          multiplier--;
        }
        cout << *(myGame->td);
        if (hasgraph){
          myGame->gd->displayBoard();
        }
      } else if (cmd == "down") {
         Down command{myGame};
         invoker.setCommand(&command);
         while(multiplier > 0){
           invoker.action();
           multiplier--;
        }
        cout << *(myGame->td);
        if (hasgraph){
          myGame->gd->displayBoard();
        }      
      }
      else if (cmd == "clockwise") {
        Clockwise command{myGame};
        invoker.setCommand(&command);
        while(multiplier > 0){
          invoker.action();
          multiplier--;
        }
        cout << *(myGame->td);
        if (hasgraph){
          myGame->gd->displayBoard();
        }      
      }
      else if (cmd == "counterclockwise") {
        Counterclockwise command{myGame};
        invoker.setCommand(&command);
        while(multiplier > 0){
          invoker.action();
          multiplier--;
        }
        cout << *(myGame->td);
        if (hasgraph){
          myGame->gd->displayBoard();
        }      
      }
      else if (cmd == "drop") {
        Drop command{myGame};
        invoker.setCommand(&command);
        while(multiplier > 0){
          invoker.action();
          multiplier--;
        }
        cout << *(myGame->td);
        if (hasgraph){
          myGame->gd->display();
        }      
      }
      else if (cmd == "levelup") {
        Levelup command{myGame};
        invoker.setCommand(&command);
        while(multiplier > 0){
          invoker.action();
          multiplier--;
        }
        cout << *(myGame->td);
        if (hasgraph){
          myGame->gd->displayScoreBoard();
        }      
      }
      else if (cmd == "leveldown") {
        Leveldown command{myGame};
        invoker.setCommand(&command);
        while(multiplier > 0){
          invoker.action();
          multiplier--;
        }
        cout << *(myGame->td);
        if (hasgraph){
          myGame->gd->displayScoreBoard();
        }      
      }
      else if (cmd == "norandom") {
        string filename;

        if (readFromFile){
          filestream >> filename;
          if (filestream.eof()){
            readFromFile = false;
            filestream.close();
            continue;
          }
        }
        else{
          if (!(cin >> filename)) break;
        }

        NoRandom command{myGame,filename};
        invoker.setCommand(&command);
        invoker.action();
        cout << *(myGame->td);
      }
      else if (cmd == "random") {
        Random command{myGame};
        invoker.setCommand(&command);
        invoker.action();
        cout << *(myGame->td);
      }
      else if (cmd == "sequence") {
        string filename;

        if (readFromFile){
          filestream >> filename;
          filestream.close();
        }
        else{
          if (!(cin >> filename)) break;
        }

        filestream.open(filename);
        if (filestream) {
          readFromFile = true;
        }
      }
      else if (cmd == "I") {
        I_Command command{myGame};
        invoker.setCommand(&command);
        invoker.action();
        cout << *(myGame->td);
        if (hasgraph){
          myGame->gd->displayBoard();
        }      
      }
      else if (cmd == "J") {
        J_Command command{myGame};
        invoker.setCommand(&command);
        invoker.action();
        cout << *(myGame->td);
        if (hasgraph){
          myGame->gd->displayBoard();
        }      
      }
      else if (cmd == "L") {
        L_Command command{myGame};
        invoker.setCommand(&command);
        invoker.action();
        cout << *(myGame->td);
        if (hasgraph){
          myGame->gd->displayBoard();
        }      
      }
      else if (cmd == "O") {
        O_Command command{myGame};
        invoker.setCommand(&command);
        invoker.action();
        cout << *(myGame->td);
        if (hasgraph){
          myGame->gd->displayBoard();
        }      
      }
      else if (cmd == "S") {
        S_Command command{myGame};
        invoker.setCommand(&command);
        invoker.action();
        cout << *(myGame->td);
        if (hasgraph){
          myGame->gd->displayBoard();
        }      
      }
      else if (cmd == "Z") {
        Z_Command command{myGame};
        invoker.setCommand(&command);
        invoker.action();
        cout << *(myGame->td);
        if (hasgraph){
          myGame->gd->displayBoard();
        }      
      }
      else if (cmd == "T") {
        T_Command command{myGame};
        invoker.setCommand(&command);
        invoker.action();
        cout << *(myGame->td);
        if (hasgraph){
          myGame->gd->displayBoard();
        }      
      }
      else if (cmd == "restart") {
        Restart command{myGame};
        invoker.setCommand(&command);
        invoker.action();
        cout << *(myGame->td);
        if (hasgraph){
          myGame->gd->display();
        }      
      }
      else if (cmd == "hint") {
        Hint command{myGame};
        invoker.setCommand(&command);
        invoker.action();
        cout << *(myGame->td);
        if (hasgraph){
          myGame->gd->display();
        }
        myGame->deleteHintBlock();
      }
      else {
        continue;
      }
    }
  }
  catch (ios::failure &) {}  // Any I/O failure quits
  delete myGame;
}


