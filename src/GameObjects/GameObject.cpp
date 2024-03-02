#include "GameObject.h"
#include "Components/Component.h"

AGameObject::~AGameObject()
{
    for (AComponent* component : m_components)
    {
        delete component;
    }
}

bool AGameObject::Update(float _deltaTime)
{
    for (AComponent* component : m_components)
    {
        component->Update(_deltaTime);
    }
    return true;
}

void AGameObject::Render()
{
    for (AComponent* component : m_components)
    {
        component->Render();
    }
}