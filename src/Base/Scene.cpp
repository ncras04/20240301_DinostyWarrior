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
    std::string returnValue = "";
    std::list<AGameObject*> toRemove = std::list<AGameObject*>();
    for (AGameObject* go : m_objects)
    {
        if (!go->Update(_deltaTime))
        {
            toRemove.push_back(go);
        }
    }

    for (int i = 0; i < m_objects.size(); i++)
    {
        if (nullptr == m_objects[i]->m_Collider)
        {
            continue;
        }
        for (int j = i + 1; j < m_objects.size(); j++)
        {
            if (nullptr == m_objects[j]->m_Collider)
            {
                continue;
            } 
            if (m_objects[i]->m_Collider->Intersect(m_objects[j]->m_Collider))
            {
                M5.Speaker.tone(261.626, 1000, 1);
                if (m_objects[i]->m_Collider->GetTag() == "Player"
                    || m_objects[j]->m_Collider->GetTag() == "Player")
                    {
                        // Game over
                        returnValue = "GameOver";
                    }
            }
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

    return returnValue;
}