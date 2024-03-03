#ifndef LIBRARY_OBSTACLESPAWNER_H
#define LIBRARY_OBSTACLESPAWNER_H
#include <vector>

#include "GameObject.h"

class Obstacle;

class ObstacleSpawner : public AGameObject
{
    public:
        ObstacleSpawner(int _minSpawnDelay, int _maxSpawnDelay);
        ~ObstacleSpawner();
    public:
        virtual bool Update(float _deltaTime) noexcept override;

    protected:
        virtual void SetupObstacle(Obstacle* _obstacle) noexcept = 0;
    protected:
        int m_minSpawnDelay = 0;
        int m_maxSpawnDelay = 0;
        float m_timeSinceLastSpawn = 0;
        std::vector<Obstacle*> m_activeObstacles = std::vector<Obstacle*>();
        std::vector<Obstacle*> m_inactiveObstacles = std::vector<Obstacle*>();
};
#endif // LIBRARY_OBSTACLESPAWNER_H