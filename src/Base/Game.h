#ifndef LIBRARY_GAME_H
#define LIBRARY_GAME_H
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
#endif // LIBRARY_GAME_H