#pragma once

#include "Core/GameObject.h"

class Item : public GameObject
{
  public:
    Item(const std::string &name);
    ~Item() override;

    virtual void Use();

  protected:
    SpriteComponent *Sprite;
    LayerComponent *Layer;
};