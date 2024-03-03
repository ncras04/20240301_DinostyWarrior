#include "CatObstacle.h"
#include "Components/AnimationRenderComponent.h"
#include "Images/CatImage.h"

CatObstacle::CatObstacle(int _movementSpeed)
{
    m_movementSpeed = _movementSpeed;
    m_baseMovementSpeed = _movementSpeed;
    m_Collider = new BoxCollision(this, 0, 0, 53, 62);
    SetTag("Cat");
    m_components.push_back(new AnimationRenderComponent(this, 53, 62, 0.5f, 2, cat_walk_animation));
    m_components.push_back(m_Collider);
}

bool CatObstacle::Update(float _deltaTime) noexcept
{
    if (!Obstacle::Update(_deltaTime))
        return false;

    m_waitTimeLeft -= _deltaTime;
    if (m_waitTimeLeft < 0 && !m_isCharging)
    {
        m_isCharging = true;
        m_movementSpeed = m_baseMovementSpeed * 3;
    }

    return true;
}

void CatObstacle::SetMovementSpeed(int _movementSpeed) noexcept
{
    m_waitTimeLeft = 2.5f;
    m_isCharging = false;
    
    m_baseMovementSpeed = _movementSpeed;
    m_movementSpeed = m_baseMovementSpeed * 0.5f;
}