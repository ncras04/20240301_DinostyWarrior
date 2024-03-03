#include "Obstacle.h"

#include "Components/ImageRenderComponent.h"
#include "Images/TrashImage.h"

Obstacle::Obstacle(int _movementSpeed)
{
    m_movementSpeed = _movementSpeed;
    m_Collider = new BoxCollision(this, "Obstacle", 0, 0, 29, 32);

    m_components.push_back(new ImageRenderComponent(this, 29, 32, trashImage));
    m_components.push_back(m_Collider);
}

bool Obstacle::Update(float _deltaTime) noexcept
{
    float posX = GetPosX();

    posX -= m_movementSpeed * _deltaTime;

    SetPosX(posX);
    AGameObject::Update(_deltaTime);

    return true;
}