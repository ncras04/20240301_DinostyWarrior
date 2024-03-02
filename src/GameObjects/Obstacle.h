#ifndef LIBRARY_OBSTACLE_H
#define LIBRARY_OBSTACLE_H
#include "GameObject.h"

class Obstacle: public AGameObject
{
    public:
        Obstacle(int _movementSpeed);

    public:
        virtual bool Update(float _deltaTime) noexcept override;

    protected:
        int m_movementSpeed = 0;
};
#endif // LIBRARY_OBSTACLE_H