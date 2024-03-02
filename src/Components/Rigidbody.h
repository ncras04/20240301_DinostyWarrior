#ifndef LIBRARY_RIGIDBODY_H
#define LIBRARY_RIGIDBODY_H
#include "Component.h"

class AGameObject;

class Rigidbody : public AComponent
{
    public:
        Rigidbody(AGameObject* _owner);
    public:
        virtual void Update(float _deltaTime) noexcept override;
        virtual void Render() noexcept override;

        inline void SetMass(int _mass) { m_mass = _mass; }
        inline void SetFloorLevel(int _level) { m_floorLevel = _level; }
        inline void SetDrag(float _drag) { m_drag = _drag; }
        inline bool GetIsGrounded() { return m_isGrounded; }

        void AddForce(float _x, float _y);
        void AddImpulse(float _x, float _y);
    private:
        static float s_gravity;

        bool m_isGrounded = false;
    protected:
        float m_velocityX = 0;
        float m_velocityY = 0;
        float m_accelerationX = 0;
        float m_accelerationY = 0;
        int m_floorLevel = 0;
        int m_mass = 1;
        float m_drag = 1;
};
#endif // LIBRARY_RIGIDBODY_H