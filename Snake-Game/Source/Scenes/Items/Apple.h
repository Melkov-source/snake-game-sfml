#pragma once

#include "Core/Assets/AssetsManager.h"

#include "Item.h"

const sf::IntRect APPLE = {0, 64, 64, 64};

class Apple final : public Item
{
  public:
    Apple();
    ~Apple() override;

    void Use() override;

  private:
    sf::Texture *_textureAtlas;
};