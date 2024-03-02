#ifndef LIBRARY_GAMEOBJECT_H
#define LIBRARY_GAMEOBJECT_H
#include <vector>

// Forward declarations
class AComponent;

class AGameObject 
{
    public:
        ~AGameObject();
    public:
        virtual bool Update(float _deltaTime);
        virtual void Render();

        inline float GetPosX() { return m_posX; }
        inline float GetPosY() { return m_posY; }
        inline void SetPosX(float _posX) {m_posX = _posX; };
        inline void SetPosY(float _posY) {m_posY = _posY; };

    protected:
        std::vector<AComponent*> m_components = std::vector<AComponent*>();

    private:
        float m_posX = 0;
        float m_posY = 0;
};
#endif // LIBRARY_GAMEOBJECT_H