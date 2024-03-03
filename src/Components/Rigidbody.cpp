#include "M5Cardputer.h"

#include "Rigidbody.h"
#include "GameObjects/GameObject.h"

float Rigidbody::s_gravity = 100.0f;

Rigidbody::Rigidbody(AGameObject* _owner) : AComponent(_owner)
{

}

void Rigidbody::AddForce(float _x, float _y)
{
    // f = m * a
    // a = f / m
    m_accelerationX += _x / m_mass;
    m_accelerationY += _y / m_mass;
}

void Rigidbody::AddImpulse(float _x, float _y)
{
    m_velocityX = _x / m_mass;
    m_velocityY = _y / m_mass;
}

void Rigidbody::Update(float _deltaTime) noexcept
{
    float posX = m_owner->GetPosX();
    float posY = m_owner->GetPosY();

    m_accelerationX = m_accelerationX - (m_accelerationX * (m_drag * _deltaTime));
    m_accelerationY = m_accelerationY - (m_accelerationY * (m_drag * _deltaTime));

    // v = a * t
    m_velocityX += m_accelerationX * _deltaTime;
    m_velocityY += m_accelerationY * _deltaTime;
    m_velocityY -= Rigidbody::s_gravity * _deltaTime;

   // M5Cardputer.Display.println("Velociy X" + String(m_velocityX));
   // M5Cardputer.Display.println("Velociy Y" + String(m_velocityY));
   // M5Cardputer.Display.println("Acceleration X" + String(m_accelerationX));
   // M5Cardputer.Display.println("Acceleration Y" + String(m_accelerationY));

    // s = v * t
    posX += m_velocityX * _deltaTime;
    posY += m_velocityY * _deltaTime;

    if (posY < m_floorLevel)
    {
        posY = m_floorLevel;
        m_isGrounded = true;
        m_accelerationY = 0;
    }
    else if (posY > m_floorLevel)
    {
        m_isGrounded = false;
    }

    m_owner->SetPosX(posX);
    m_owner->SetPosY(posY);
}

void Rigidbody::Render() noexcept
{

}

void Rigidbody::ResetAcceleration()
{
    m_accelerationX = 0;
    m_accelerationY = 0;
}