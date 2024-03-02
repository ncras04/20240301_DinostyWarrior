#include "MainScene.h"
#include "Audio/AudioManager.h"
#include "Audio/Sounds.h"
#include "GameObjects/Player.h"
#include "GameObjects/Ground.h"
#include "GameObjects/Obstacle.h"

MainScene::MainScene()
{
    Player* player = new Player();
    player->SetPosX(20);
    player->SetPosY(100);
    m_objects.push_back(player);
    Ground* ground = new Ground(50, 20);
    ground->SetPosY(20);
    m_objects.push_back(ground);

    Obstacle* obstacle = new Obstacle(10);
    obstacle->SetPosX(M5Cardputer.Display.width());
    obstacle->SetPosY(M5Cardputer.Display.height() * 0.5f);
    m_objects.push_back(obstacle);
    
    AudioManager::Get()->PlayOneshot(testintro, sizeof(testintro), ESoundTypes::AMBIENT);
    AudioManager::Get()->PlayRepeatOneshot(test, sizeof(test), ESoundTypes::AMBIENT);
}