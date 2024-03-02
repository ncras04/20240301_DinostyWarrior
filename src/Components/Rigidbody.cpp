#include "M5Cardputer.h"

#include "Rigidbody.h"
#include "GameObjects/GameObject.h"

float Rigidbody::s_gravity = 40.0f;

Rigidbody::Rigidbody(AGameObject* _owner) : AComponent(_owner)
{

}

void Rigidbody::AddForce(float _x, float _y)
{
    // f = m * a
    // a = f / m
    m_accelerationX += _x / this->m_mass;
    m_accelerationY += _y / this->m_mass;
}

void Rigidbody::AddImpulse(float _x, float _y)
{
    m_velocityX = _x / m_mass;
    m_velocityY = _y / m_mass;
}

void Rigidbody::Update(float _deltaTime) noexcept
{
    float posX = this->m_owner->GetPosX();
    float posY = this->m_owner->GetPosY();

    m_accelerationX = m_accelerationX - (m_accelerationX * (this->m_drag * _deltaTime));
    m_accelerationY = m_accelerationY - (m_accelerationY * (this->m_drag * _deltaTime));

    // v = a * t
    this->m_velocityX += this->m_accelerationX * _deltaTime;
    this->m_velocityY += this->m_accelerationY * _deltaTime;
    this->m_velocityY -= Rigidbody::s_gravity * _deltaTime;

   // M5Cardputer.Display.println("Velociy X" + String(this->m_velocityX));
   // M5Cardputer.Display.println("Velociy Y" + String(this->m_velocityY));
   // M5Cardputer.Display.println("Acceleration X" + String(this->m_accelerationX));
   // M5Cardputer.Display.println("Acceleration Y" + String(this->m_accelerationY));

    // s = v * t
    posX += this->m_velocityX * _deltaTime;
    posY += this->m_velocityY * _deltaTime;

    if (posY < this->m_floorLevel)
    {
        posY = m_floorLevel;
        m_isGrounded = true;
        m_accelerationY = 0;
    }
    else if (posY > this->m_floorLevel)
    {
        m_isGrounded = false;
    }

    m_owner->SetPosX(posX);
    m_owner->SetPosY(posY);
}

void Rigidbody::Render() noexcept
{

}