#include "MainScene.h"
#include "Audio/AudioManager.h"
#include "Audio/Sounds.h"
#include "GameObjects/Player.h"
#include "GameObjects/Ground.h"
#include "GameObjects/Obstacle.h"
#include "GameObjects/Score.h"

MainScene::MainScene()
{
    Player* player = new Player(10);
    player->SetPosX(20);
    m_objects.push_back(player);
    Ground* ground = new Ground(50, 20);
    ground->SetPosY(20);
    m_objects.push_back(ground);

    Obstacle* obstacle = new Obstacle(10);
    obstacle->SetPosX(M5Cardputer.Display.width());
    obstacle->SetPosY(M5Cardputer.Display.height() * 0.6f);
    m_objects.push_back(obstacle);
    
    obstacle = new Obstacle(20);
    obstacle->SetPosX(M5Cardputer.Display.width());
    obstacle->SetPosY(M5Cardputer.Display.height() * 0.2f);
    m_objects.push_back(obstacle);
    
    m_objects.push_back(new Score(1.0f));
    // AudioManager::Get()->PlayOneshot(testintro, sizeof(testintro), ESoundTypes::AMBIENT);
    // AudioManager::Get()->PlayRepeatOneshot(test, sizeof(test), ESoundTypes::AMBIENT);
}