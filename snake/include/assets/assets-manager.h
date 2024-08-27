#pragma once

#include <SFML/Graphics.hpp>
#include <map>

namespace assets
{
    const std::string ASSETS_ROOT_PATH = "assets";
    
    class AssetsManager
    {
    public:
         sf::Texture* load_texture(const std::string& texture_path);

    private:
        std::map<std::string, sf::Texture*> textures_;
    };
}


