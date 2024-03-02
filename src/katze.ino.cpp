# 1 "C:\\Users\\Student\\AppData\\Local\\Temp\\tmphxa147ku"
#include <Arduino.h>
# 1 "C:/Users/Student/Downloads/20240301_DinostyWarrior/src/katze.ino"
#include "M5Cardputer.h"
#include "Base/Game.h"

Game game = Game();
void setup();
void loop();
#line 6 "C:/Users/Student/Downloads/20240301_DinostyWarrior/src/katze.ino"
void setup()
{
  game.Setup();
}

void loop()
{
  game.Run();
}