#include "M5Cardputer.h"
#include "Base/Game.h"

Game* game = Game::Get();

void setup() 
{
  game->Setup();
}

void loop() 
{
  game->Run();  
}
