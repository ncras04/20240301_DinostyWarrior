#include "M5Cardputer.h"
#include "ObstacleSpawner.h"
#include "Obstacle.h"
#include "Base/Game.h"
#include "Base/Scene.h"
#include "Ground.h"
#include "GroundObstacle.h"
#include "AirObstacle.h"
#include "CatObstacle.h"
#include "BallonObstacle.h"
#include "Audio/AudioManager.h"
#include "Audio/Sounds.h"

#include <list>
ObstacleSpawner::ObstacleSpawner(int _minSpawnDelay, int _maxSpawnDelay, Ground *_ground, int _obstaclePool)
{
    m_ground = _ground;
    Obstacle *obstacle = nullptr;
    for (int i = 0; i < _obstaclePool; i++)
    {
        obstacle = new GroundObstacle(20);
        m_inactiveObstacles.push_back(obstacle);
    }
    for (int i = 0; i < _obstaclePool; i++)
    {
        obstacle = new AirObstacle(20);
        m_inactiveObstacles.push_back(obstacle);
    }
    for (int i = 0; i < _obstaclePool; i++)
    {
        obstacle = new BallonObstacle(20);
        m_inactiveObstacles.push_back(obstacle);
    }
    m_catObstacle = new CatObstacle(20);

    m_minSpawnDelay = _minSpawnDelay;
    m_maxSpawnDelay = _maxSpawnDelay;
}

ObstacleSpawner::~ObstacleSpawner()
{
    for (Obstacle *obstacle : m_inactiveObstacles)
    {
        delete obstacle;
    }

    for (Obstacle *obstacle : m_activeObstacles)
    {
        delete obstacle;
    }
}

bool ObstacleSpawner::Update(float _deltaTime) noexcept
{
    if (!AGameObject::Update(_deltaTime))
        return false;

    m_timeSinceLastSpawn += _deltaTime;
    m_timeUntilCat -= _deltaTime;
    if (m_timeSinceLastSpawn >= 0)
    {
        static const double fraction = 1.0 / (RAND_MAX + 1.0);
        if (m_timeUntilCat < 0)
        {
            M5Cardputer.Speaker.stop();

            m_timeUntilCat = m_minTimeBetweenCats + static_cast<int>((m_minMaxTimeBetweenCats - m_minTimeBetweenCats + 1) * (std::rand() * fraction));
            Obstacle *obstacle = m_catObstacle;
            if (nullptr == obstacle)
                return "";

            SetupObstacle(obstacle);

            m_activeObstacles.push_back(obstacle);

            Game::Get()->GetActiveScene()->AddGameObject(obstacle);

            AudioManager::Get()->PlaySound(SFXAlert, sizeof(SFXAlert));
            AudioManager::Get()->PlaySound(BGMCatBossEvent, sizeof(BGMCatBossEvent));
            // AudioManager::Get()->PlayBGMRepeat(BGMLevel, sizeof(BGMLevel));
        }
        else
        {
            if (m_inactiveObstacles.size() > 0)
            {

                int index = rand() % m_inactiveObstacles.size();
                Obstacle *obstacle = m_inactiveObstacles[index];
                if (nullptr == obstacle)
                    return "";
                m_inactiveObstacles.erase(m_inactiveObstacles.begin() + index);

                SetupObstacle(obstacle);

                m_activeObstacles.push_back(obstacle);

                Game::Get()->GetActiveScene()->AddGameObject(obstacle);
            }
        }
        int time = m_minSpawnDelay + static_cast<int>((m_maxSpawnDelay - m_minSpawnDelay + 1) * (std::rand() * fraction));
        m_timeSinceLastSpawn = -1 * time;
    }
    std::list<Obstacle *> toRemove = std::list<Obstacle *>();
    for (Obstacle *obstacle : m_activeObstacles)
    {
        if (obstacle->GetPosX() < -20)
        {
            toRemove.push_back(obstacle);
        }
    }

    for (Obstacle *obstacle : toRemove)
    {
        if (obstacle->GetTag() != "Cat")
        {
            m_inactiveObstacles.push_back(obstacle);
        }

        std::vector<Obstacle *>::iterator obstaclePosition = std::find(m_activeObstacles.begin(), m_activeObstacles.end(), obstacle);
        if (obstaclePosition != m_activeObstacles.end())
        {
            m_activeObstacles.erase(obstaclePosition);
        }
        Game::Get()->GetActiveScene()->RemoveGameObject(obstacle);
    }
    return true;
}

void ObstacleSpawner::SetupObstacle(Obstacle *_obstacle) noexcept
{
    _obstacle->SetPosX(m_ground->GetLastPositionX());

    if (_obstacle->GetTag() == "Air")
    {
        _obstacle->SetPosY(70);
    }
    else if (_obstacle->GetTag() == "Cat")
    {
        _obstacle->SetPosY(0);
    }
    else
    {
        _obstacle->SetPosY(m_ground->GetLastPositionY() + 20);
    }
    _obstacle->SetMovementSpeed(m_ground->GetScrollSpeed());
}