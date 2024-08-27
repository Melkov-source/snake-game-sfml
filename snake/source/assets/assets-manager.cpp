#include "../../include/assets/assets-manager.h"

#include "../../include/utils/logger.h"

namespace assets
{
    sf::Texture* AssetsManager::load_texture(const std::string& texture_path)
    {
        if(this->textures_.count(texture_path))
        {
            return this->textures_[texture_path];
        }
        
        const auto texture = new sf::Texture();

        const std::string target_path = ASSETS_ROOT_PATH + '/' + texture_path;
        
        const auto area = sf::IntRect(10,10,32, 32);

        if(texture->loadFromFile(target_path, area) == false)
        {
            utils::error("Not found texture: %a", target_path);

            return nullptr;
        }

        this->textures_[texture_path] = texture;

        return texture;
    }
}
