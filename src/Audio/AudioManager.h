#ifndef LIBRARY_AUDIOMANAGER_H
#define LIBRARY_AUDIOMANAGER_H
#include "M5Cardputer.h"

enum class ESoundChannels : unsigned char 
{
    ZUNDAMON,
    MUSIC,
    EFFECTS,
    EFFECT2,
    ZUNDAQUEUE,
};

class AudioManager 
{
    public:
        static AudioManager* Get();
    public:
        void PlayBGM(const uint8_t* _data, int _length);
        void PlayVoice(const uint8_t* _data, int _length);
        void PlayQueuedVoice(const uint8_t* _data, int _length);
        void PlaySound(const uint8_t* _data, int _length);
        void PlayBGMRepeat(const uint8_t* _data, int _length);
        void Update();

    private:
        AudioManager() {}
        void Init();
        
    private:
        static AudioManager* s_instance;
        uint8_t m_currentVolume{120};
};
#endif // LIBRARY_AUDIOMANAGER_H