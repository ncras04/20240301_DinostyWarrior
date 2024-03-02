#pragma once
#include <vector>

class AGameObject;

class Scene
{
    public:
        ~Scene();
    public:
        virtual char* Update(float _deltaTime) noexcept;

    protected:
        std::vector<AGameObject*> m_objects = std::vector<AGameObject*>();
};