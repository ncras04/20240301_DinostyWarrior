#include "M5Cardputer.h"

#include "Window.h"
#include "Components/ImageRenderComponent.h"
#include "Images/Header/WindowImage.h"

Window::Window(int _scrollSpeed)
{
    m_scrollSpeed = _scrollSpeed;

    m_components.push_back(new ImageRenderComponent(this, 66, 36, windowImage));
}

bool Window::Update(float _deltaTime) noexcept
{
    float posX = GetPosX();
    posX -= m_scrollSpeed * _deltaTime;
    if (posX < -80)
    {
        posX = 250;
    }
    SetPosX(posX);

    AGameObject::Update(_deltaTime);
    return true;
}