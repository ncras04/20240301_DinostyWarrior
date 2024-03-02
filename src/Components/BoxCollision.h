#ifndef LIBRARY_BOXCOLLISION_H
#define LIBRARY_BOXCOLLISION_H

#include "Component.h"
#include <string>

class AGameObject;

class BoxCollision : public AComponent
{
    public:
        BoxCollision(AGameObject* _owner, std::string _tag, int _minX, int _minY, int _maxX, int _maxY);

    public:
        inline std::string GetTag() const noexcept { return m_tag; }
        bool Intersect(const BoxCollision* _other) const noexcept;
        virtual void Update(float _deltaTime) noexcept override;
        virtual void Render() noexcept override;
        
    private:
        std::string m_tag = "NONE";
        int m_minX = 0;
        int m_minY = 0;
        int m_maxX = 0;
        int m_maxY = 0;
};
#endif // LIBRARY_BOXCOLLISION_H