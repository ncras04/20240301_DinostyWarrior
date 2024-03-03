#ifndef LIBRARY_BRICKS_H
#define LIBRARY_BRICKS_H

#include <list>

#include "GameObject.h"

class Bricks : public AGameObject
{
    public:
        Bricks(int _scrollSpeed);

    public:
        virtual bool Update(float _deltaTime) noexcept override;

        inline int GetScrollSpeed() const noexcept { return m_scrollSpeed; }

    private:
        float m_scrollSpeed = 10;
};  
#endif // LIBRARY_BRICKS_H