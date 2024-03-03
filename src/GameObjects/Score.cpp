#include "M5Cardputer.h"

#include "Score.h"

Score::Score(float _scoreChangePerSecond)
{
    m_scoreChangePerSecond = _scoreChangePerSecond;
}

bool Score::Update(float _deltaTime)
{
    m_currentScore += m_scoreChangePerSecond * _deltaTime;

    M5Cardputer.Display.setTextColor(BLACK);
    M5Cardputer.Display.setCursor(160,10, 2);
    M5Cardputer.Display.print("brojac: " + String((int)m_currentScore));

    return true;
}