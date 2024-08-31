#pragma once

#include "SFML/Graphics.hpp"

namespace Core::Scenes
{
    class Scene
    {
    public:
        std::string Name;
        bool IsReady;

        explicit Scene(std::string name);
        
        void Update(const float deltaTime);
        void Render(const sf::RenderTarget& renderTarget);
        void Dispose();
    };
}
