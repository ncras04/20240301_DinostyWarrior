#ifndef LIBRARY_WINDOW_H
#define LIBRARY_WINDOW_H

#include <list>

#include "GameObject.h"

class Window : public AGameObject
{
    public:
        Window(int _scrollSpeed);

    public:
        virtual bool Update(float _deltaTime) noexcept override;

        inline int GetScrollSpeed() const noexcept { return m_scrollSpeed; }

    private:
        float m_scrollSpeed = 10;
};  
#endif // LIBRARY_WINDOW_H