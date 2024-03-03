#ifndef LIBRARY_BALLONOBSTACLE_H
#define LIBRARY_BALLONOBSTACLE_H

#include "M5Cardputer.h"
#include "Obstacle.h"
#include "Images/Header/BalloonImage.h"

class BallonObstacle : public Obstacle
{
    public:
        BallonObstacle(int _movementSpeed) : Obstacle(_movementSpeed, "Air", 38, 34, ballonImage) {}
};
#endif // LIBRARY_BALLONOBSTACLE_H