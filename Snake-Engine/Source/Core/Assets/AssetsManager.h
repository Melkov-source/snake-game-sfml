#pragma once
#include <iostream>
#include <map>

#include "SFML/Graphics/Texture.hpp"

class AssetsManager
{
public:
    static sf::Texture* LoadTexture(const std::string& path)
    {
        if (_textures.count(path))
        {
            return _textures[path];
        }

        const auto texture = new sf::Texture();

        if (!texture->loadFromFile(path))
        {
            std::cout << "Texture not loaded for target path: " << path << "\n";
            return nullptr;
        }

        _textures[path] = texture;

        return texture;
    }

private:
    inline static std::map<std::string, sf::Texture*> _textures;
};
