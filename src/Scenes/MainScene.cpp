#include "MainScene.h"
#include "Audio/AudioManager.h"
#include "Audio/Sounds.h"
#include "GameObjects/Player.h"
#include "GameObjects/Ground.h"

MainScene::MainScene()
{
    Player* player = new Player();
    player->SetPosX(20);
    player->SetPosY(100);
    m_objects.push_back(player);
    Ground* ground = new Ground(50, 20);
    ground->SetPosY(20);
    m_objects.push_back(ground);

     AudioManager::Get()->PlayOneshot(test, sizeof(test), ESoundTypes::AMBIENT);
}