#include "Scene.h"
#include "M5Cardputer.h"
#include "Gameobjects/GameObject.h"

Scene::~Scene()
{
    for (AGameObject* go : m_objects)
    {
        delete go;
    }
}

std::string Scene::Update(float _deltaTime) noexcept
{    
    for (AGameObject* go : m_objects)
    {
        go->Update(_deltaTime);
    }

    for (AGameObject* go : m_objects)
    {
        go->Render();
    }

    return std::string("");
}