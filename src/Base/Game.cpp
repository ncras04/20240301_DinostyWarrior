#include "M5Cardputer.h"
#include "Game.h"
#include "Scene.h"
#include "Scenes/MainScene.h"
#include "Components/ImageRenderComponent.h"
#include "Audio/AudioManager.h"
#include "Audio/Sounds.h"
#include <M5Unified.h>

Game* Game::s_instance = nullptr;

Game* Game::Get()
{
    if (nullptr == s_instance)
    {
        s_instance = new Game();
    }
    return s_instance;
}

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
    M5Cardputer.Display.setTextColor(BLACK);
    M5Cardputer.Display.setTextDatum(middle_center);
    M5Cardputer.Display.setFont(&fonts::Orbitron_Light_32);
    M5Cardputer.Display.setTextSize(textsize, textsize);

    ImageRenderComponent::s_ScreenWidth = M5Cardputer.Display.width();
    ImageRenderComponent::s_ScreenHeight = M5Cardputer.Display.height();

    
    AudioManager::Get()->PlayQueuedVoice(ZundaHallo, sizeof(ZundaHallo));
    AudioManager::Get()->PlayQueuedVoice(ZundaLassUnsSpielen, sizeof(ZundaLassUnsSpielen));
    AudioManager::Get()->PlayQueuedVoice(ZundaLosGehts, sizeof(ZundaLosGehts));
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
    delay(100);
    M5Cardputer.Display.fillScreen(0xF695);
    std::string newScene = m_activeScene->Update(deltaSeconds);
    if (newScene != "")
    {
        // Load new scene
        if (newScene == "GameOver")
        {
            M5Cardputer.Display.setTextColor(BLACK);
            M5Cardputer.Display.setTextDatum(middle_center);
            M5Cardputer.Display.setFont(&fonts::Orbitron_Light_32);
            M5Cardputer.Display.setTextSize(1, 1);
            M5Cardputer.Display.drawString("Game Over!", M5Cardputer.Display.width() * 0.5f, M5Cardputer.Display.height() * 0.5f);
            delete m_activeScene;
            M5Cardputer.Speaker.stop();
            AudioManager::Get()->PlayVoice(ZundaGemein, sizeof(ZundaGemein));
            delay(5000);
            m_activeScene = new MainScene();
            currentFrame = millis();
        }
    }
    static float lastCheckTime = 0;
    static float temperature = temperatureRead();
    lastCheckTime += deltaSeconds * temperature / 25.0f;

    if (lastCheckTime > 1.0f)
    {
        temperature = temperatureRead();
        //M5Cardputer.Speaker.tone(temperature * 100, 250, 7, true);

        lastCheckTime -= 1.0f;
    }
    M5Cardputer.Display.setCursor(0,10, 2);
    M5Cardputer.Display.print("celzija: " + String(temperature));
    lastFrame = currentFrame;

    AudioManager::Get()->Update();
}

Scene* Game::GetActiveScene() const noexcept
{
    return m_activeScene;
}