#pragma once
#include <string>

#include "SFML/Graphics/RenderTarget.hpp"

namespace Core
{
    class GameObject
    {
    public:
        std::string Name;
    
        void Update(float deltaTime);
        void Render(sf::RenderTarget& renderTarget);
    };
}

