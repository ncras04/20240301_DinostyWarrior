#pragma once
#include <vector>

// Forward declarations
class AComponent;

class AGameObject 
{
    public:
        ~AGameObject();
    public:
        virtual void Update(float _deltaTime);
        virtual void Render();

        inline int GetPosX() { return this->m_posX; }
        inline int GetPosY() { return this->m_posY; }
        inline void SetPosX(int _posX) {this->m_posX = _posX; };
        inline void SetPosY(int _posY) {this->m_posY = _posY; };

    protected:
        std::vector<AComponent*> m_components = std::vector<AComponent*>();

    private:
        int m_posX = 0;
        int m_posY = 0;
};