#include "AnimationRenderComponent.h"

AnimationRenderComponent::AnimationRenderComponent(AGameObject* _owner, int _imageWidth, int _imageHeight, float _frameTime, int _totalFrames, const unsigned short** _frames)
    : ImageRenderComponent(_owner, _imageWidth, _imageHeight, _frames[0])
{
    m_frameTime = _frameTime;
    m_frames = _frames;
    m_totalFrames = _totalFrames;
}

void AnimationRenderComponent::Update(float _deltaTime) noexcept
{
    m_timeUntilNextFrame -= _deltaTime;
    
    if (m_timeUntilNextFrame < 0)
    {
        m_timeUntilNextFrame = m_frameTime;

        m_currentIndex = (m_currentIndex + 1) % m_totalFrames;

        m_data = m_frames[m_currentIndex];
    }

    ImageRenderComponent::Update(_deltaTime);
}
