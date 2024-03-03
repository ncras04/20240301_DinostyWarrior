#ifndef LIBRARY_AIROBSTACLE_H
#define LIBRARY_AIROBSTACLE_H

#include "M5Cardputer.h"
#include "Obstacle.h"
#include "Images/BirdImage.h"

class AirObstacle : public Obstacle
{
    public:
        AirObstacle(int _movementSpeed) : Obstacle(_movementSpeed, "Air", 18, 16, birdImage) {}
};
#endif // LIBRARY_AIROBSTACLE_H