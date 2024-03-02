#include "M5Cardputer.h"
#include "SoundObject.h"
#include "Images/Dino.h"
#include "Audio/Sounds.h"
#include "Audio/AudioManager.h"

SoundObject::SoundObject(int _frequency) 
{
  this->frequency = _frequency;
  this->SetPosY(M5Cardputer.Display.height() * 0.5f);
}

void SoundObject::Update(float _deltaTime)
{
  int newPos = (this->GetPosX() + (int)(50 * _deltaTime)) % M5Cardputer.Display.width();
  this->SetPosX(newPos);

  if (M5Cardputer.Keyboard.isKeyPressed('a'))
  {
    // M5Cardputer.Speaker.tone(newPos * 5, 250);
    AudioManager::Get()->PlayOneshot(katze_sound_file, sizeof(katze_sound_file), ESoundTypes::EFFECTS);
    // M5Cardputer.Speaker.playWav(wav_with_header, sizeof(wav_with_header), 1, 0, false);
  }
  if (M5Cardputer.Keyboard.isKeyPressed('s'))
  {
    // M5Cardputer.Speaker.tone(newPos * 5, 250);
    AudioManager::Get()->PlayOneshot(background_sound_file,  sizeof(background_sound_file), ESoundTypes::AMBIENT);
    // M5Cardputer.Speaker.playWav(background_wav_with_header, sizeof(background_wav_with_header), 1, 1, false);
  }
}


void SoundObject::Render()
{
  uint16_t c = rand();
  // M5Cardputer.Display.fillCircle(this->GetPosX(), this->GetPosY(), 17, c);
  M5Cardputer.Display.pushImage(this->GetPosX(), this->GetPosY(),  56, 61, dino);
  m5::rtc_time_t time = M5.Rtc.getTime();
  M5Cardputer.Display.drawString(String(time.hours) + "|" + String(time.minutes) + "|" + String(time.seconds),
                                   M5Cardputer.Display.width() / 2,
                                   M5Cardputer.Display.height() / 2);
}