#include "BoxCollision.h"
#include "GameObjects/GameObject.h"
#include "M5Cardputer.h"
#include "ImageRenderComponent.h"

BoxCollision::BoxCollision(AGameObject* _owner, int _minX, int _minY, int _maxX, int _maxY) : AComponent(_owner)
{
    m_minX = _minX;
    m_minY = _minY;
    m_maxX = _maxX;
    m_maxY = _maxY;
} 

bool BoxCollision::Intersect(const BoxCollision* _other) const noexcept
{
    float posX = m_owner->GetPosX();
    float posY = m_owner->GetPosY();

    float otherPosX = _other->m_owner->GetPosX();
    float otherPosY = _other->m_owner->GetPosY();

    if (posX + m_maxX < otherPosX + _other->m_minX || posX + m_minX > otherPosX + _other->m_maxX) 
        return false;
    if (posY + m_maxY < otherPosY + _other->m_minY || posY + m_minY > otherPosY + _other->m_maxY) 
        return false;

    return true; 
}

void BoxCollision::Update(float _deltaTime) noexcept
{

}

void BoxCollision::Render() noexcept
{
    return;
    
    float posX = m_owner->GetPosX();
    float posY = m_owner->GetPosY() + m_minY + (m_maxY - m_minY);

    posY = ImageRenderComponent::s_ScreenHeight - posY;

    M5Cardputer.Display.drawRect(posX + m_minX, posY, m_maxX - m_minX, m_maxY - m_minY, GREEN);
}