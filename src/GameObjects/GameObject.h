#pragma once

class AGameObject 
{
    public:
        virtual void Update(float _deltaTime) = 0;
        virtual void Render() = 0;

        inline int GetPosX() { return this->m_posX; }
        inline int GetPosY() { return this->m_posY; }
        inline void SetPosX(int _posX) {this->m_posX = _posX; };
        inline void SetPosY(int _posY) {this->m_posY = _posY; };

    private:
        int m_posX = 0;
        int m_posY = 0;
};