#ifndef LIBRARY_MAINSCENE_H
#define LIBRARY_MAINSCENE_H

#include "Base/Scene.h"
#include <vector>

class Ground;
class Obstacle;

class MainScene : public Scene
{
    public:
        MainScene();
        ~MainScene();
    public:
        virtual std::string Update(float _deltaSeconds) noexcept override;

    private:
        Ground* m_ground = nullptr;
        std::vector<Obstacle*> m_activeObstacles = std::vector<Obstacle*>();
        std::vector<Obstacle*> m_inactiveObstacles = std::vector<Obstacle*>();
};
#endif // LIBRARY_MAINSCENE_H