#pragma once
#include "GameObject.h"

class SoundObject : public GameObject 
{
  public:
    SoundObject(int _frequency);
    virtual void Update(float _deltaTime);
    virtual void Render();
    void MakeSound();

  private:
    int frequency = 8000;
};