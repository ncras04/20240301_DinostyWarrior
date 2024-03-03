#include "AudioManager.h"

AudioManager *AudioManager::s_instance = nullptr;

AudioManager *AudioManager::Get()
{
    if (nullptr == s_instance)
    {
        s_instance = new AudioManager();
        s_instance->Init();
    }
    return s_instance;
}

void AudioManager::Init()
{
    M5Cardputer.Speaker.setVolume(m_currentVolume);

    M5Cardputer.Speaker.setChannelVolume((uint8_t)ESoundChannels::ZUNDAMON, 255);
    M5Cardputer.Speaker.setChannelVolume((uint8_t)ESoundChannels::EFFECTS, 255);
    M5Cardputer.Speaker.setChannelVolume((uint8_t)ESoundChannels::EFFECT2, 255);
    M5Cardputer.Speaker.setChannelVolume((uint8_t)ESoundChannels::MUSIC, 255);
}

void AudioManager::Update()
{
    M5Cardputer.Speaker.setChannelVolume((uint8_t)ESoundChannels::MUSIC, 255 - (150 * M5Cardputer.Speaker.isPlaying((uint8_t)ESoundChannels::ZUNDAMON)));

    if (M5Cardputer.Keyboard.isKeyPressed(';'))
    {
        m_currentVolume += 15;
        if (m_currentVolume > 255)
            m_currentVolume = 255;

        M5Cardputer.Speaker.setVolume(m_currentVolume);
    }

    if (M5Cardputer.Keyboard.isKeyPressed('.'))
    {
        m_currentVolume -= 15;
        if (m_currentVolume < 0)
            m_currentVolume = 0;

        M5Cardputer.Speaker.setVolume(m_currentVolume);
    }
}

void AudioManager::PlayBGMRepeat(const uint8_t *_data, int _length)
{
    M5Cardputer.Speaker.playWav(_data, _length, 0, (int)ESoundChannels::MUSIC, false);
}

void AudioManager::PlayBGM(const uint8_t *_data, int _length)
{
    M5Cardputer.Speaker.playWav(_data, _length, 1, (int)ESoundChannels::MUSIC, false);
}

void AudioManager::PlayVoice(const uint8_t *_data, int _length)
{
    M5Cardputer.Speaker.playWav(_data, _length, 1, (int)ESoundChannels::ZUNDAMON, true);
}

void AudioManager::PlayQueuedVoice(const uint8_t *_data, int _length)
{
    M5Cardputer.Speaker.playWav(_data, _length, 1, (int)ESoundChannels::ZUNDAMON, false);
}

void AudioManager::PlaySound(const uint8_t *_data, int _length)
{
    auto ch = ESoundChannels::EFFECTS;

    auto r = 0;
    r += M5Cardputer.Speaker.isPlaying((int)ch);
    r += M5Cardputer.Speaker.isPlaying((int)ch + 1);

    if (r % 2 == 1)
        ch = ESoundChannels::EFFECT2;

    M5Cardputer.Speaker.playWav(_data, _length, 1, (int)ch, true);
}