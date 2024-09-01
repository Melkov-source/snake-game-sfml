#include "AssetsManager.h"

std::map<std::string, sf::Texture*> AssetsManager::_textures;

sf::Texture* AssetsManager::LoadTexture(const std::string& path, const sf::IntRect& area)
{
    if(_textures.count(path) != false)
    {
        return _textures[path];
    }
    
    const auto texture = new sf::Texture();

    if(texture->loadFromFile(path, area) == false)
    {
        std::cout << "Texture not loaded for target path: " << path << "\n";
        return nullptr;
    }

    _textures[path] = texture;

    return texture;
}
