#ifndef LIBRARY_GAME_H
#define LIBRARY_GAME_H
#include <vector>

class Scene;

class Game
{
    public:
        static Game* Get();
    public:
        void Setup();
        void Run();

        Scene* GetActiveScene() const noexcept;
    private:
        Game() {};

    private:
        static Game* s_instance;
    private:
        Scene* m_activeScene = nullptr;
};
#endif // LIBRARY_GAME_H