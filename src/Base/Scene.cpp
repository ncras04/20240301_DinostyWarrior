#include "Scene.h"
#include "M5Cardputer.h"
#include "Gameobjects/GameObject.h"

Scene::~Scene()
{
    for (AGameObject* go : this->m_objects)
    {
        delete go;
    }
}

char* Scene::Update(float _deltaTime)
{    
    for (AGameObject* go : this->m_objects)
    {
        go->Update(_deltaTime);
    }

    for (AGameObject* go : this->m_objects)
    {
        go->Render();
    }

    return "";
}