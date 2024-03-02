#pragma once
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

    private:
        AudioManager() {}

    private:
        static AudioManager* s_instance;
};