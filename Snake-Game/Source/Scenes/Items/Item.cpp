#include "Item.h"

Item::Item(const std::string &name) : GameObject(name)
{
    Sprite = new SpriteComponent(*this);
    Layer = new LayerComponent(*this);

    Layer->Order = 2;

    AddComponent(Sprite);
    AddComponent(Layer);
}

Item::~Item() = default;

void Item::Use()
{
}
