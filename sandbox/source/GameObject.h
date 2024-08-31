#pragma once
#include <string>

#include "Component.h"

class GameObject
{
public:
    void AddComponent(Component& component);
    Component& GetComponent(std::pmr::string componentName);

    
};
