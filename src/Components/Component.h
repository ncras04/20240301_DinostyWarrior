#ifndef LIBRARY_COMPONENT_H
#define LIBRARY_COMPONENT_H
class AGameObject;

class AComponent
{
    public:
        AComponent(AGameObject* _owner) { m_owner = _owner; }
    public:
        virtual void Update(float _deltaTime) noexcept = 0;
        virtual void Render() noexcept = 0;

    protected:
        AGameObject* m_owner = nullptr;
};
#endif // LIBRARY_COMPONENT_H