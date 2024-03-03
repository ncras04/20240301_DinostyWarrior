#ifndef LIBRARY_GAMEOBJECT_H
#define LIBRARY_GAMEOBJECT_H
#include <vector>
#include <string>

#include "Components/BoxCollision.h"

// Forward declarations
class AComponent;

class AGameObject 
{
    public:
        ~AGameObject();
    public:
        virtual bool Update(float _deltaTime);
        virtual void Render();

        inline float GetPosX() const noexcept { return m_posX; }
        inline float GetPosY() const noexcept { return m_posY; }
        inline void SetPosX(float _posX) noexcept {m_posX = _posX; };
        inline void SetPosY(float _posY) noexcept {m_posY = _posY; };
        inline std::string GetTag() const noexcept { return m_tag; }
        inline void SetTag(std::string _tag) noexcept { m_tag = _tag; }
    public:
        BoxCollision* m_Collider = nullptr;
    protected:
        std::vector<AComponent*> m_components = std::vector<AComponent*>();
        std::string m_tag = "";

    private:
        float m_posX = 0;
        float m_posY = 0;
};
#endif // LIBRARY_GAMEOBJECT_H