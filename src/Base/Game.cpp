#include "M5Cardputer.h"
#include "Game.h"
#include "Scene.h"
#include "Scenes/MainScene.h"
#include "Components/ImageRenderComponent.h"
#include <M5Unified.h>

void Game::Setup()
{
    auto cfg = M5.config();
    M5Cardputer.begin(cfg, true);

    int textsize = M5Cardputer.Display.height() / 60;
    if (textsize == 0) 
    {
        textsize = 1;
    }
    textsize = 1;
    M5Cardputer.Display.setSwapBytes(true);
    M5Cardputer.Display.setRotation(1);
    M5Cardputer.Display.setTextColor(GREEN);
    M5Cardputer.Display.setTextDatum(middle_center);
    M5Cardputer.Display.setFont(&fonts::Orbitron_Light_32);
    M5Cardputer.Display.setTextSize(textsize);

    ImageRenderComponent::s_ScreenWidth = M5Cardputer.Display.width();
    ImageRenderComponent::s_ScreenHeight = M5Cardputer.Display.height();

    m_activeScene = new MainScene();
}

void Game::Run()
{    
    static int lastFrame = millis();
    int currentFrame = millis();

    float deltaSeconds = (currentFrame - lastFrame) * 0.001f;

    M5Cardputer.update();
    if (m_activeScene == nullptr)
    {
        return;
    }
    M5Cardputer.Display.fillScreen(TFT_WHITE);

    std::string new_scene = m_activeScene->Update(deltaSeconds);
    if (new_scene != "")
    {
        // Load new scene
    }
    lastFrame = currentFrame;
}