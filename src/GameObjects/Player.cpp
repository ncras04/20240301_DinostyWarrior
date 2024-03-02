#include "M5Cardputer.h"

#include "Player.h"
#include "Components/ImageRenderComponent.h"
#include "Components/Rigidbody.h"
#include "Images/DinoImage.h"

Player::Player()
{
    m_rigidbody = new Rigidbody(this);

    m_rigidbody->SetMass(1);
    m_rigidbody->SetFloorLevel(100);
    m_rigidbody->SetDrag(0);

    m_components.push_back(m_rigidbody);
    m_components.push_back(new ImageRenderComponent(this, 56, 61, dinoImage));
}

void Player::Update(float _deltaTime) noexcept
{
    static bool isHolding = false;
    static float holdTime = 0;
    if (m_rigidbody->GetIsGrounded() || isHolding)
    {
        if (holdTime >= 1.0f)
        {
            isHolding = false;
        }
        else
        {
            if (M5Cardputer.BtnA.wasPressed())
            {
                m_rigidbody->AddImpulse(0, 50);
                isHolding = true; 
                holdTime = 0.0f;
            }
            if (M5Cardputer.BtnA.isHolding())
            {
                holdTime += _deltaTime;
                m_rigidbody->AddForce(0, 50 * _deltaTime);   
            }
            if (M5Cardputer.BtnA.wasReleased())
            {
                isHolding = false;
            }
        }
    }

    AGameObject::Update(_deltaTime);
}