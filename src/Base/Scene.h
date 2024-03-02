#pragma once
#include <vector>
#include <string>

class AGameObject;

class Scene
{
    public:
        ~Scene();
    public:
        virtual std::string Update(float _deltaTime) noexcept;

    protected:
        std::vector<AGameObject*> m_objects = std::vector<AGameObject*>();
};