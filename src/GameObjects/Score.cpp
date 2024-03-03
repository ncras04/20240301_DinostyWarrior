#include "M5Cardputer.h"

#include "Score.h"
#include "Audio/AudioManager.h"
#include "Audio/Sounds.h"


Score::Score(float _scoreChangePerSecond)
{
    m_scoreChangePerSecond = _scoreChangePerSecond;
}

bool Score::Update(float _deltaTime)
{
    m_currentScore += m_scoreChangePerSecond * _deltaTime;


    if((int)m_currentScore % 10 == 0 && (int)m_currentScore != 0)
    {
        int tmp{};
        tmp = (int)m_currentScore % 20 == 0 ? 0 : 1;
        AudioManager::Get()->PlayVoice(ZundaOkay, sizeof(ZundaOkay));
    }
    M5Cardputer.Display.setTextColor(BLACK);
    M5Cardputer.Display.setCursor(160,10, 2);
    M5Cardputer.Display.print("brojac: " + String((int)m_currentScore));

    return true;
}