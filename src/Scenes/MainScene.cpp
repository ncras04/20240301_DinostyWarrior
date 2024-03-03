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
    m_ground = new Ground(50, 20);
    m_ground->SetPosY(20);
    m_objects.push_back(m_ground);

    Obstacle* obstacle = new Obstacle(10);
    obstacle->SetPosX(M5Cardputer.Display.width());
    obstacle->SetPosY(M5Cardputer.Display.height() * 0.6f);
    m_inactiveObstacles.push_back(obstacle);
    
    obstacle = new Obstacle(20);
    obstacle->SetPosX(M5Cardputer.Display.width());
    obstacle->SetPosY(M5Cardputer.Display.height() * 0.2f);
    m_inactiveObstacles.push_back(obstacle);

    obstacle = new Obstacle(20);
    obstacle->SetPosX(M5Cardputer.Display.width());
    obstacle->SetPosY(M5Cardputer.Display.height() * 0.2f);
    m_inactiveObstacles.push_back(obstacle);

    obstacle = new Obstacle(20);
    obstacle->SetPosX(M5Cardputer.Display.width());
    obstacle->SetPosY(M5Cardputer.Display.height() * 0.2f);
    m_inactiveObstacles.push_back(obstacle);
    
    m_objects.push_back(new Score(1.0f));
    AudioManager::Get()->PlayOneshot(testbossintro, sizeof(testbossintro), ESoundTypes::AMBIENT);
    AudioManager::Get()->PlayRepeatOneshot(testboss, sizeof(testboss), ESoundTypes::AMBIENT);
}

MainScene::~MainScene()
{
    for (Obstacle* obstacle : m_inactiveObstacles)
    {
        delete obstacle;
    }

    for (Obstacle* obstacle : m_activeObstacles)
    {
        delete obstacle;
    }
}

std::string MainScene::Update(float _deltaTime) noexcept
{
    std::string mainReturn = Scene::Update(_deltaTime);
    if (mainReturn != "")
        return mainReturn;

    if (rand() % 30 == 0)
    {
        if (m_inactiveObstacles.size() > 0)
        {
            Obstacle* obstacle = m_inactiveObstacles[0];
            if (nullptr == obstacle)
                return "";
            if (nullptr == m_ground)
                return "";

            m_inactiveObstacles.erase(m_inactiveObstacles.begin());

            obstacle->SetPosX(m_ground->GetLastPositionX());
            obstacle->SetPosY(m_ground->GetLastPositionY() + 20);
            obstacle->SetMovementSpeed(m_ground->GetScrollSpeed());

            m_activeObstacles.push_back(obstacle);
            m_objects.push_back(obstacle);
        }
    }   
    std::list<Obstacle*> toRemove = std::list<Obstacle*>();
    for (Obstacle* obstacle : m_activeObstacles)
    {
        if (obstacle->GetPosX() < -5)
        {
            toRemove.push_back(obstacle);
        }
    }

    for (Obstacle* obstacle : toRemove)
    {
        m_inactiveObstacles.push_back(obstacle);

        std::vector<Obstacle*>::iterator obstaclePosition = std::find(m_activeObstacles.begin(), m_activeObstacles.end(), obstacle);
        if (obstaclePosition != m_activeObstacles.end()) 
        {
            m_activeObstacles.erase(obstaclePosition);
        }

        std::vector<AGameObject*>::iterator position = std::find(m_objects.begin(), m_objects.end(), obstacle);
        if (position != m_objects.end()) 
        {
            m_objects.erase(position);
        }
    }

    return "";
}