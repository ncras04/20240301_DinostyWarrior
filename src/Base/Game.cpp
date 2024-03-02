#include "M5Cardputer.h"
#include "Game.h"
#include "Gameobjects/GameObject.h"
#include "GameObjects/SoundObject.h"
#include <M5Unified.h>

void Game::Setup()
{
    auto cfg = M5.config();
    M5Cardputer.begin(cfg);

    int textsize = M5Cardputer.Display.height() / 60;
    if (textsize == 0) 
    {
        textsize = 1;
    }
    textsize = 1;
    M5Cardputer.Display.setRotation(1);
    M5Cardputer.Display.setTextColor(GREEN);
    M5Cardputer.Display.setTextDatum(middle_center);
    M5Cardputer.Display.setFont(&fonts::Orbitron_Light_32);
    M5Cardputer.Display.setTextSize(textsize);
    this->m_objects.push_back(new SoundObject(8000));
}

void Game::Run()
{    
    M5Cardputer.update();
    for (AGameObject* go : this->m_objects)
    {
        go->Update(0.2f);
        delay(100);
    }
    // Clear screen
    M5Cardputer.Display.fillScreen(TFT_BLACK);
    for (AGameObject* go : this->m_objects)
    {
        go->Render();
    }
}