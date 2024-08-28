#pragma once
#include <string>

#include "asset-type.h"
#include "../../lib/json.hpp"
#include "SFML/OpenGL.hpp"

class Prefab
{
public:
    GUID id;
    ASSET_TYPE asset_type;
    std::string asset_name;
    nlohmann::json data;
};
