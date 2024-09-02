#include "AssetsManager.h"

std::map<std::string, sf::Texture*> AssetsManager::_textures;

sf::Texture* AssetsManager::LoadTexture(const std::string& path, const sf::IntRect& area)
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
