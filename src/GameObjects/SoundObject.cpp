#include "M5Cardputer.h"
#include "SoundObject.h"
#include "Images/Dino.h"
#include "Audio/Sounds.h"
#include "Audio/AudioManager.h"
#include "Components/ImageRenderComponent.h"

SoundObject::SoundObject(int _frequency) 
{
  this->frequency = _frequency;
  this->SetPosY(M5Cardputer.Display.height() * 0.5f);

  this->m_components.push_back(new ImageRenderComponent(this, 56, 61, dino));
}

void SoundObject::Update(float _deltaTime)
{
  float newPos = this->GetPosX() + 50 * _deltaTime;
  if (newPos > M5Cardputer.Display.width())
  {
    newPos = 0;
  }
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
  M5Cardputer.Display.drawString(String(millis()) + "|" + String(_deltaTime),
                                   M5Cardputer.Display.width() / 2,
                                   M5Cardputer.Display.height() / 2);
  AGameObject::Update(_deltaTime);
}


void SoundObject::Render()
{
  AGameObject::Render();
}