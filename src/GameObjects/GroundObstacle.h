#ifndef LIBRARY_GROUNDOBSTACLE_H
#define LIBRARY_GROUNDOBSTACLE_H

#include "M5Cardputer.h"
#include "Obstacle.h"
#include "Images/TrashImage.h"

class GroundObstacle : public Obstacle
{
    public:
        GroundObstacle(int _movementSpeed) : Obstacle(_movementSpeed, "Ground", 29, 32, trashImage) {}
};
#endif // LIBRARY_GROUNDOBSTACLE_H