#pragma once
#include <vector>

class Scene;

class Game
{
    public:
        void Setup();
        void Run();

    private:
        Scene* m_activeScene = nullptr;
};