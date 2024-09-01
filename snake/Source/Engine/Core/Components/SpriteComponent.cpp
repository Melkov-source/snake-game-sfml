#include "SpriteComponent.h"

#include "../GameObject.h"


SpriteComponent::SpriteComponent(GameObject& gameObject): Component(gameObject)
{
}

SpriteComponent::~SpriteComponent()
{
}

void SpriteComponent::SetTexture(const sf::Texture& texture)
{
    this->_texture = texture;

    this->_sprite.setTexture(texture);
}

void SpriteComponent::SetSize(const sf::Vector2f& size)
{
}

void SpriteComponent::SetColor(const sf::Color& color)
{
    this->_sprite.setColor(color);
}

void SpriteComponent::Update(float deltaTime)
{
    Component::Update(deltaTime);
    
    this->_sprite.setPosition(this->_gameObject->getPosition());
    this->_sprite.setRotation(this->_gameObject->getRotation());
    this->_sprite.setScale(this->_gameObject->getScale());
}

void SpriteComponent::Render(sf::RenderTarget& renderTarget)
{
    renderTarget.draw(this->_sprite);
}

void SpriteComponent::Dispose()
{
}
