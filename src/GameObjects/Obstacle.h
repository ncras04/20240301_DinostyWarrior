#ifndef LIBRARY_OBSTACLE_H
#define LIBRARY_OBSTACLE_H
#include "GameObject.h"

class Obstacle: public AGameObject
{
    public:
        Obstacle(int _movementSpeed, std::string _tag, int _imageWidth, int _imageHeight, const unsigned short* _data);

    public:
        inline void SetMovementSpeed(int _movementSpeed) noexcept { m_movementSpeed = _movementSpeed; }
        virtual bool Update(float _deltaTime) noexcept override;

    protected:
        int m_movementSpeed = 0;
};
#endif // LIBRARY_OBSTACLE_H