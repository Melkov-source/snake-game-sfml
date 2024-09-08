#pragma once
#include <iostream>
#include <map>

#include "SFML/Graphics/Texture.hpp"

class AssetsManager
{
public:
    static sf::Texture* LoadTexture(const std::string& path, const sf::IntRect& area = sf::IntRect())
    {
        std::string key = path + std::to_string(area.left) + std::to_string(area.top) + std::to_string(area.width) + std::to_string(area.height);

        if (_textures.count(key))
        {
            return _textures[key];
        }

        const auto texture = new sf::Texture();

        if (!texture->loadFromFile(path, area))
        {
            std::cout << "Texture not loaded for target path: " << path << "\n";
            return nullptr;
        }

        _textures[key] = texture;

        return texture;
    }

private:
    inline static std::map<std::string, sf::Texture*> _textures;
};
