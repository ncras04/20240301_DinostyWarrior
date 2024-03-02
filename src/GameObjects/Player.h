#pragma once

#include "GameObject.h"

// forward declarations
class Rigidbody;

class Player : public AGameObject
{
    public:
        Player();

    public:
        virtual void Update(float _deltaTime) noexcept override;

    protected:
        Rigidbody* m_rigidbody = nullptr;
};