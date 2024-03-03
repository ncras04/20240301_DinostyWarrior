#include "GroundSpawner.h"
#include "Ground.h"
#include "GroundObstacle.h"
#include "AirObstacle.h"

GroundSpawner::GroundSpawner(int _minSpawnDelay, int _maxSpawnDelay, Ground* _ground, int _obstaclePool) : ObstacleSpawner(_minSpawnDelay, _maxSpawnDelay)
{
    m_ground = _ground;
    Obstacle* obstacle = nullptr;
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
}

void GroundSpawner::SetupObstacle(Obstacle* _obstacle) noexcept
{
    _obstacle->SetPosX(m_ground->GetLastPositionX());

    if (_obstacle->GetTag() == "Air")
    {
        _obstacle->SetPosY(70);
    }
    else
    {
        _obstacle->SetPosY(m_ground->GetLastPositionY() + 20);
    }
    _obstacle->SetMovementSpeed(m_ground->GetScrollSpeed());
}