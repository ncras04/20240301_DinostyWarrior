#include "MainScene.h"
#include "GameObjects/Player.h"
#include "Audio/AudioManager.h"
#include "Audio/Sounds.h"

MainScene::MainScene()
{
    m_objects.push_back(new Player());
    // m_objects.push_back(new SoundObject(8000));

    AudioManager::Get()->PlayOneshot(los_gehts_soundfile, sizeof(los_gehts_soundfile), ESoundTypes::AMBIENT);
}