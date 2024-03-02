#pragma once

#include <list>

#include "GameObject.h"

class Ground : public AGameObject
{
    public:
        Ground(int _scrollSpeed, int _spacePerPoint);

    public:
        virtual bool Update(float _deltaTime) noexcept override;
        virtual void Render() noexcept override;
    protected:
        float GenerateNextPoint(float _previousHeight);

    private:
        float m_scrollSpeed = 10;
        int m_spacePerPoint = 5;
        float m_currentLocation = 0;
        std::list<float> m_points = std::list<float>();
};  