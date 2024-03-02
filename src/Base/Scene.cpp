#include "Scene.h"
#include "M5Cardputer.h"
#include "Gameobjects/GameObject.h"
#include <list>

Scene::~Scene()
{
    for (AGameObject* go : m_objects)
    {
        delete go;
    }
}

std::string Scene::Update(float _deltaTime) noexcept
{    
    std::list<AGameObject*> toRemove = std::list<AGameObject*>();
    for (AGameObject* go : m_objects)
    {
        if (!go->Update(_deltaTime))
        {
            toRemove.push_back(go);
        }
    }

    for (AGameObject* go : toRemove)
    {
        std::vector<AGameObject*>::iterator position = std::find(m_objects.begin(), m_objects.end(), go);
        if (position != m_objects.end()) 
        {
            m_objects.erase(position);
        }
        delete go;
    }

    for (AGameObject* go : m_objects)
    {
        go->Render();
    }

    return std::string("");
}