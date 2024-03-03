#include "MainScene.h"
#include "Audio/AudioManager.h"
#include "Audio/Sounds.h"
#include "GameObjects/Player.h"
#include "GameObjects/Ground.h"
#include "GameObjects/Obstacle.h"
#include "GameObjects/Score.h"
#include "GameObjects/GroundSpawner.h"

MainScene::MainScene()
{
    Player* player = new Player(10);
    player->SetPosX(20);
    m_objects.push_back(player);
    Ground* ground = new Ground(50, 20);
    ground->SetPosY(20);
    m_objects.push_back(ground);
    m_objects.push_back(new GroundSpawner(2, 5, ground, 3));
    m_objects.push_back(new Score(1.0f));
    AudioManager::Get()->PlayOneshot(testbossintro, sizeof(testbossintro), ESoundTypes::AMBIENT);
    AudioManager::Get()->PlayRepeatOneshot(testboss, sizeof(testboss), ESoundTypes::AMBIENT);
}