#include "SnakeElement.h"

SnakeElement::SnakeElement(const sf::Texture& texture, const SNAKE_ELEMENT type) : GameObject("SnakeElement")
{
    this->_sprite = this->AddComponent<SpriteComponent>();

    this->_sprite->SetTexture(texture);
    this->_sprite->SetTextureRect(type == HEAD ? SNAKE_HEAD : SNAKE_BODY);

    this->_layer = this->AddComponent<LayerComponent>();
    this->_layer->Order = 10;
}

SnakeElement::~SnakeElement()
{

}

void SnakeElement::SetOrder(int32_t order)
{
    this->_layer->Order = order;
}
