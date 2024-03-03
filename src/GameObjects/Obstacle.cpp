#include "Obstacle.h"

#include "Components/ImageRenderComponent.h"
#include "Images/Header/TrashImage.h"

Obstacle::Obstacle(int _movementSpeed, std::string _tag, int _imageWidth, int _imageHeight, const unsigned short* _data)
{
    m_movementSpeed = _movementSpeed;
    m_Collider = new BoxCollision(this, 0, 0, _imageWidth, _imageHeight);
    SetTag(_tag);
    m_components.push_back(new ImageRenderComponent(this, _imageWidth, _imageHeight, _data));
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

void Obstacle::SetMovementSpeed(int _movementSpeed) noexcept
{
    m_movementSpeed = _movementSpeed;
}