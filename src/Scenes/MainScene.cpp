#include "MainScene.h"
#include "Audio/AudioManager.h"
#include "Audio/Sounds.h"
#include "GameObjects/Player.h"
#include "GameObjects/Ground.h"
#include "GameObjects/Obstacle.h"
#include "GameObjects/Score.h"
#include "GameObjects/ObstacleSpawner.h"
#include "GameObjects/Bricks.h"
#include "GameObjects/Window.h"

#define SOUNDDEBUG

MainScene::MainScene()
{
    Ground* ground = new Ground(50, 20);
    ground->SetPosY(-15);
    ground->SetPosX(-240);
    m_objects.push_back(ground);
    ground = new Ground(50, 20);
    ground->SetPosY(-15);
    ground->SetPosX(0);
    m_objects.push_back(ground);
    ground = new Ground(50, 20);
    ground->SetPosY(-15);
    ground->SetPosX(240);
    m_objects.push_back(ground);
    m_objects.push_back(new ObstacleSpawner(2, 5, ground, 2));
    m_objects.push_back(new Score(1.0f));

    Bricks* bricks = new Bricks(50);
    bricks->SetPosX(45);
    bricks->SetPosY(90);
    m_objects.push_back(bricks);

    bricks = new Bricks(50);
    bricks->SetPosX(170);
    bricks->SetPosY(65);
    m_objects.push_back(bricks);

    Window* window = new Window(50);
    window->SetPosX(120);
    window->SetPosY(70);
    m_objects.push_back(window);

    Player* player = new Player(10);
    player->SetPosX(20);
    m_objects.push_back(player);
    AudioManager::Get()->PlayBGM(BGMLevelIntro, sizeof(BGMLevelIntro));
    AudioManager::Get()->PlayBGMRepeat(BGMLevel, sizeof(BGMLevel));
}