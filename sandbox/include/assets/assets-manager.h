#pragma once

#include <SFML/Graphics.hpp>
#include <map>

#include "../../lib/json.hpp"
#include "../../source/core/prefab.h"
#include "../core/game-object.h"

namespace assets
{
    const std::string ASSETS_ROOT_PATH = "assets";
    
    class AssetsManager
    {
    public:
        sf::Texture* load_texture(const std::string& texture_path);
        Prefab load_prefab(const std::string& prefab_path);

        nlohmann::json create_prefab(const std::string& path, const Engine::GameObject& game_object);
        

    private:
        std::map<std::string, sf::Texture*> textures_;
    };
}


