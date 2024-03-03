#ifndef LIBRARY_BOXCOLLISION_H
#define LIBRARY_BOXCOLLISION_H

#include "Component.h"
#include <string>

class AGameObject;

class BoxCollision : public AComponent
{
    public:
        BoxCollision(AGameObject* _owner, int _minX, int _minY, int _maxX, int _maxY);

    public:
        bool Intersect(const BoxCollision* _other) const noexcept;
        virtual void Update(float _deltaTime) noexcept override;
        virtual void Render() noexcept override;
        
    private:
        int m_minX = 0;
        int m_minY = 0;
        int m_maxX = 0;
        int m_maxY = 0;
};
#endif // LIBRARY_BOXCOLLISION_H