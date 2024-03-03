#include "M5Cardputer.h"
#include "ObstacleSpawner.h"
#include "Obstacle.h"
#include "Base/Game.h"
#include "Base/Scene.h"

#include <list>
ObstacleSpawner::ObstacleSpawner(int _minSpawnDelay, int _maxSpawnDelay)
{
   m_minSpawnDelay = _minSpawnDelay;
   m_maxSpawnDelay = _maxSpawnDelay;
}

ObstacleSpawner::~ObstacleSpawner()
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

bool ObstacleSpawner::Update(float _deltaTime) noexcept
{
    if (!AGameObject::Update(_deltaTime))
        return false;

    m_timeSinceLastSpawn += _deltaTime;
    if (m_timeSinceLastSpawn >= 0)
    {
        if (m_inactiveObstacles.size() > 0)
        {
            Obstacle* obstacle = m_inactiveObstacles[0];
            if (nullptr == obstacle)
                return "";
            m_inactiveObstacles.erase(m_inactiveObstacles.begin());

            SetupObstacle(obstacle);

            m_activeObstacles.push_back(obstacle);

            Game::Get()->GetActiveScene()->AddGameObject(obstacle);
        }
        static const double fraction = 1.0 / (RAND_MAX + 1.0);
        int time = m_minSpawnDelay + static_cast<int>((m_maxSpawnDelay - m_minSpawnDelay + 1) * (std::rand() * fraction));
        m_timeSinceLastSpawn = -1 * time;
    }   
    std::list<Obstacle*> toRemove = std::list<Obstacle*>();
    for (Obstacle* obstacle : m_activeObstacles)
    {
        if (obstacle->GetPosX() < -20)
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
        Game::Get()->GetActiveScene()->RemoveGameObject(obstacle);
    }
    return true;
}