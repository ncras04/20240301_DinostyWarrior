#include "MainScene.h"
#include "Audio/AudioManager.h"
#include "Audio/Sounds.h"
#include "GameObjects/Player.h"
#include "GameObjects/Ground.h"
#include "GameObjects/Obstacle.h"
#include "GameObjects/Score.h"
#include "GameObjects/ObstacleSpawner.h"

#define SOUNDDEBUG

MainScene::MainScene()
{

    AudioManager::Get()->PlayBGM(BGMLevelIntro, sizeof(BGMLevelIntro));
    AudioManager::Get()->PlayBGMRepeat(BGMLevel, sizeof(BGMLevel));

#ifndef SOUNDDEBUG
    Player *player = new Player(10);
    player->SetPosX(20);
    m_objects.push_back(player);
    Ground *ground = new Ground(50, 20);
    ground->SetPosY(20);
    m_objects.push_back(ground);
    m_objects.push_back(new ObstacleSpawner(2, 5, ground, 2));
    m_objects.push_back(new Score(1.0f));
    AudioManager::Get()->Play(BGMLevelIntro);
    AudioManager::Get()->PlayRepeat(BGMLevel);
#endif // SOUNDDEBUG
}

std::string MainScene::Update(float _deltaTime) noexcept
{

    if (M5Cardputer.Keyboard.isKeyPressed('a'))
        AudioManager::Get()->PlayVoice(ZundaScheisse, sizeof(ZundaScheisse));

    return Scene::Update(_deltaTime);
}