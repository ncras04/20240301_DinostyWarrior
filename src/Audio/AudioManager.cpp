#include "AudioManager.h"

AudioManager* AudioManager::s_instance = nullptr;

AudioManager* AudioManager::Get()
{
    if (nullptr == s_instance)
    {
        s_instance = new AudioManager();
    }
    return s_instance;
}

void AudioManager::PlayOneshot(const uint8_t* _data, int _length, ESoundTypes _type)
{
    M5Cardputer.Speaker.playWav(_data, _length, 0, (int)_type, true);
}