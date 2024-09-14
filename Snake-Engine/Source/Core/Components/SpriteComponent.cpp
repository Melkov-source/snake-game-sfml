#include "SpriteComponent.h"

#include "Core/GameObject.h"

SpriteComponent::SpriteComponent(GameObject &gameObject) : Component(gameObject)
{
    this->_sprite.setPosition(this->_gameObject->getPosition());
    this->_sprite.setRotation(this->_gameObject->getRotation());
    this->_sprite.setScale(this->_gameObject->getScale());
}

SpriteComponent::~SpriteComponent() = default;

void SpriteComponent::Update(float deltaTime)
{
    this->_sprite.setPosition(this->_gameObject->getPosition());
    this->_sprite.setRotation(this->_gameObject->getRotation());
    this->_sprite.setScale(this->_gameObject->getScale());

    Component::Update(deltaTime);
}

void SpriteComponent::Render(sf::RenderTarget &renderTarget)
{
    if (IsEnable == false)
    {
        return;
    }

    renderTarget.draw(this->_sprite);
}

void SpriteComponent::SetTexture(const sf::Texture &texture)
{
    this->_texture = texture;

    this->_sprite.setTexture(texture);
}

void SpriteComponent::SetTextureRect(const sf::IntRect area)
{
    this->_sprite.setTextureRect(area);
}

void SpriteComponent::SetColor(const sf::Color &color)
{
    this->_sprite.setColor(color);
}
