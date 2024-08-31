#include "../../include/assets/assets-manager.h"

#include <fstream>
#include <iostream>

#include "../../include/utils/logger.h"

#include "../../lib/json.hpp"

using json = nlohmann::json;

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

        if(texture->loadFromFile(target_path) == false)
        {
            utils::error("Not found texture: %a", target_path);

            return nullptr;
        }

        this->textures_[texture_path] = texture;

        return texture;
    }
    

    Prefab AssetsManager::load_prefab(const std::string& path)
    {
        const std::string target_path = ASSETS_ROOT_PATH + "/" + path;

        std::ifstream ifs(target_path);
        
        if (!ifs.is_open()) {
            std::string message = "Unable to open file for reading: " + target_path;

            std::cout << message << '\n';
        }

        // Парсим JSON
        json json_prefab;
        ifs >> json_prefab;

        auto transform_data = json_prefab["transform"];
        
        Transform transform;
        transform.position.x = transform_data["position"][0];
        transform.position.y = transform_data["position"][1];

        std::cout << transform.position.x;
    }

    json AssetsManager::create_prefab(const std::string& path, const Engine::GameObject& game_object)
    {
        json json_prefab;

        // Сериализация трансформа
        const auto& transform = game_object.get_transform(); // Предполагается, что есть метод get_transform()
        json_prefab["transform"] = {
            {"position", {transform.position.x, transform.position.y}},
            {"scale", {transform.scale.x, transform.scale.y}}
        };

        if(game_object.components_.empty() == false)
        {
            // Сериализация компонентов
            for (const auto* component : game_object.components_) {
                json json_component;
                json_component["id"] = component->id;
                json_component["name"] = component->name;
                json_component["texture_path"] = component->texture_path;
        
                json_prefab["components"].push_back(json_component);
            }
        }
       

        if(game_object.children_.empty() == false)
        {
            // Сериализация дочерних объектов
            for (const auto* child : game_object.children_) {
                json json_child;
                // Рекурсивный вызов для сериализации дочернего объекта
                json_child = create_prefab(path, *child); // Вызываем create_prefab для дочернего объекта
                json_prefab["children"].push_back(json_child);
            }
        }
     

        std::string target_path = ASSETS_ROOT_PATH + "/" + path;
        // Запись JSON в файл
        std::ofstream ofs(target_path);
        if (ofs.is_open()) {
            ofs << json_prefab.dump(4); // Запись с отступами для удобства чтения
            ofs.close();
        } else {
            std::string message = "Unable to open file for writing: " + target_path;

            std::cout << message << '\n';
        }

        return json_prefab; // Возвращаем сериализованный JSON
    }
}
