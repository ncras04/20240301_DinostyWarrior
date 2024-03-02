#pragma once
#include "GameObject.h"

class SoundObject : public AGameObject 
{
  public:
    SoundObject(int _frequency);
    virtual bool Update(float _deltaTime) override;
    virtual void Render() override;
    void MakeSound();

  private:
    int frequency = 8000;
};