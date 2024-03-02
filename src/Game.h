#pragma once
#include <vector>

class GameObject;

class Game
{
    public:
        void Setup();
        void Run();

    private:
        std::vector<GameObject*> m_objects = std::vector<GameObject*>();
};