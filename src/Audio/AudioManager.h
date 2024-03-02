#ifndef LIBRARY_AUDIOMANAGER_H
#define LIBRARY_AUDIOMANAGER_H
#include "M5Cardputer.h"

enum class ESoundTypes : unsigned char 
{
    AMBIENT,
    MUSIC,
    EFFECTS
};

class AudioManager 
{
    public:
        static AudioManager* Get();
    public:
        void PlayOneshot(const uint8_t* _data, int _length, ESoundTypes _type);
        void PlayRepeatOneshot(const uint8_t* _data, int _length, ESoundTypes _type);

    private:
        AudioManager() {}

    private:
        static AudioManager* s_instance;
};
#endif // LIBRARY_AUDIOMANAGER_H