#pragma once
#include <vector>

class AGameObject;

class Game
{
    public:
        void Setup();
        void Run();

    private:
        std::vector<AGameObject*> m_objects = std::vector<AGameObject*>();
};