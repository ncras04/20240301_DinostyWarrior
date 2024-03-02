#include "GameObject.h"
#include "Components/Component.h"

AGameObject::~AGameObject()
{
    for (AComponent* component : this->m_components)
    {
        delete component;
    }
}

void AGameObject::Update(float _deltaTime)
{
    for (AComponent* component : this->m_components)
    {
        component->Update(_deltaTime);
    }
}

void AGameObject::Render()
{
    for (AComponent* component : this->m_components)
    {
        component->Render();
    }
}