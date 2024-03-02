#ifndef LIBRARY_IMAGERENDERCOMPONENT_H
#define LIBRARY_IMAGERENDERCOMPONENT_H
#include "M5Cardputer.h"
#include "Component.h"

class AGameObject;

class ImageRenderComponent : public AComponent
{
    public:
        ImageRenderComponent(AGameObject* _owner, int _imageWidth, int _imageHeight, const unsigned short* _data);
    
    public:
        virtual void Update(float _deltaTime) noexcept override;
        virtual void Render() noexcept override;

    public:
        static int s_ScreenWidth;
        static int s_ScreenHeight;

    private:
        int m_imageWidth = 0;
        int m_imageHeight = 0;
        const unsigned short* m_data = nullptr;
};
#endif // LIBRARY_IMAGERENDERCOMPONENT_H