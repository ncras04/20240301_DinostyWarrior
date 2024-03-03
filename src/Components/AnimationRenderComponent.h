#ifndef LIBRARY_ANIMATIONRENDERCOMPONENT_H
#define LIBRARY_ANIMATIONRENDERCOMPONENT_H
#include "M5Cardputer.h"
#include "ImageRenderComponent.h"

class AnimationRenderComponent : public ImageRenderComponent
{
    public:
        AnimationRenderComponent(AGameObject* _owner, int _imageWidth, int _imageHeight, float _frameTime, int _totalFrames, const unsigned short** _frames);
    public:
        virtual void Update(float _deltaTime) noexcept override;
    private:
        int m_frameTime = 0;
        float m_timeUntilNextFrame = 0;
        int m_currentIndex = 0;
        int m_totalFrames = 0;
        const unsigned short** m_frames = nullptr;
};
#endif //LIBRARY_ANIMATIONRENDERCOMPONENT_H