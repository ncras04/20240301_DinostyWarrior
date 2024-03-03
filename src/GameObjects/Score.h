#ifndef LIBRARY_SCORE_H
#define LIBRARY_SCORE_H

#include "GameObject.h"

class Score : public AGameObject
{
    public:
        Score(float _scoreChangePerSecond);

    public:
        virtual bool Update(float _deltaTime) override;

    private:
        float m_currentScore = 0;
        float m_scoreChangePerSecond = 0;
};
#endif // LIBRARY_SCORE_H