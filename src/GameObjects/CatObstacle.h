#ifndef LIBRARY_CATOBSTACLE_H
#define LIBRARY_CATOBSTACLE_H

#include "M5Cardputer.h"
#include "Obstacle.h"

class CatObstacle : public Obstacle
{
    public:
        CatObstacle(int _movementSpeed);

    public:
        virtual bool Update(float _deltaTime) noexcept override;
        virtual void SetMovementSpeed(int _movementSpeed) noexcept override;

    private:
        int m_baseMovementSpeed = 0;
        float m_waitTimeLeft = 2;
        bool m_isCharging = false;
};
#endif // LIBRARY_CATOBSTACLE_H