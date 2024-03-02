#include "M5Cardputer.h"
#include "Game.h"

Game game = Game();

void setup() 
{
  game.Setup();
}

void loop() 
{
  game.Run();  
}
