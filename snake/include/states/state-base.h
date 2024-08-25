#pragma once

#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

#include "imgui.h"
#include "imgui-SFML.h"

class StateBase
{
public:
	explicit StateBase(sf::RenderWindow* render_window);
	virtual ~StateBase();

	virtual void exit() = 0;

	virtual void update(const float delta_time) = 0;
	virtual void render() = 0;

private:
	std::vector<sf::Texture> textures_;
	sf::RenderWindow* render_window_;
};

