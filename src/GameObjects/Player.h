#ifndef LIBRARY_PLAYER_H
#define LIBRARY_PLAYER_H
#include "GameObject.h"

// forward declarations
class Rigidbody;
class ImageRenderComponent;

class Player : public AGameObject
{
    public:
        Player(int _floorLevel);

    public:
        virtual bool Update(float _deltaTime) noexcept override;

    protected:
        Rigidbody* m_rigidbody = nullptr;
        ImageRenderComponent* m_renderer = nullptr;
};
#endif // LIBRARY_PLAYER_H