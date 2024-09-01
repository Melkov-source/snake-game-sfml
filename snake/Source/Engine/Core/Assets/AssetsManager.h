#pragma once
#include <map>

#include "SFML/Graphics/Texture.hpp"
#include <iostream>

class AssetsManager
{
public:
    static sf::Texture* LoadTexture(const std::string& path, const sf::IntRect& area = sf::IntRect());

private:
    static std::map<std::string, sf::Texture*> _textures;
};
