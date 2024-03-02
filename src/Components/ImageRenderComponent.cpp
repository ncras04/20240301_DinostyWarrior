#include "ImageRenderComponent.h"
#include "M5Cardputer.h"

#include "GameObjects/GameObject.h"

int ImageRenderComponent::s_ScreenHeight = 0;
int ImageRenderComponent::s_ScreenWidth = 0;

ImageRenderComponent::ImageRenderComponent(AGameObject* _owner, int _imageWidth, int _imageHeight, const unsigned short* _data) : AComponent(_owner)
{
    m_imageWidth = _imageWidth;
    m_imageHeight = _imageHeight;
    m_data = _data;
}

void ImageRenderComponent::Update(float _deltaTime) noexcept
{

}

void ImageRenderComponent::Render() noexcept
{
    int posX = (int)(m_owner->GetPosX() - m_imageWidth * 0.5f);
    int posY = (int)(m_owner->GetPosY() - m_imageWidth * 0.5f);

    // posX = ImageRenderComponent::s_ScreenWidth - posX;
    posY = ImageRenderComponent::s_ScreenHeight - posY;

    M5Cardputer.Display.pushImage(posX, posY,  m_imageWidth, m_imageHeight, m_data);
}

