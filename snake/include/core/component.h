#pragma once
#include <string>

#include "SFML/OpenGL.hpp"

namespace engine
{
    class Component
    {
    public:
       
        Component();
        ~Component();

        int id;
        std::string name;
        std::string texture_path;
    };
}

