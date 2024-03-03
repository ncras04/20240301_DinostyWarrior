#include "M5Cardputer.h"

#include "Bricks.h"
#include "Components/ImageRenderComponent.h"
#include "Images/Header/BricksImage.h"

Bricks::Bricks(int _scrollSpeed)
{
    m_scrollSpeed = _scrollSpeed;

    m_components.push_back(new ImageRenderComponent(this, 39, 13, bricksImage));
}

bool Bricks::Update(float _deltaTime) noexcept
{
    float posX = GetPosX();
    posX -= m_scrollSpeed * _deltaTime;
    if (posX < -40)
    {
        posX = 250;
    }
    SetPosX(posX);

    AGameObject::Update(_deltaTime);
    return true;
}