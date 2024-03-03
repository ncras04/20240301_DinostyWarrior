#ifndef LIBRARY_GROUNDSPAWNER_H
#define LIBRARY_GROUNDSPAWNER_H

#include "ObstacleSpawner.h"

class Ground;

class GroundSpawner : public ObstacleSpawner
{
    public:
        GroundSpawner(int _minSpawnDelay, int _maxSpawnDelay, Ground* _ground, int _obstaclePool);
    public:
        virtual void SetupObstacle(Obstacle* _obstacle) noexcept override;

    protected:
        Ground* m_ground = nullptr;
};

#endif // LIBRARY_GROUNDSPAWNER_H