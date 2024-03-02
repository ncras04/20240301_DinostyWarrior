#ifndef LIBRARY_PLAYER_H
#define LIBRARY_PLAYER_H
#include "GameObject.h"

// forward declarations
class Rigidbody;

class Player : public AGameObject
{
    public:
        Player(int _floorLevel);

    public:
        virtual bool Update(float _deltaTime) noexcept override;

    protected:
        Rigidbody* m_rigidbody = nullptr;
};
#endif // LIBRARY_PLAYER_H