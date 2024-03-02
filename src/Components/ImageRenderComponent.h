#pragma once

#include "Component.h"

class AGameObject;

class ImageRenderComponent : public AComponent
{
    public:
        ImageRenderComponent(AGameObject* _owner, int _imageWidth, int _imageHeight, const unsigned short* _data);
    
    public:
        virtual void Update(float _deltaTime) noexcept override;
        virtual void Render() noexcept override;

    private:
        int m_imageWidth = 0;
        int m_imageHeight = 0;
        const unsigned short* m_data = nullptr;
};