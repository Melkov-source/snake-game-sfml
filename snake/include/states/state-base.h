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

namespace state
{
	constexpr int STATE_ENTER_CODE = 1;
	constexpr int STATE_EXIT_CODE = 0;
}

class StateBase
{
public:
	int state_code;
	
	explicit StateBase(sf::RenderWindow* render_window);
	virtual ~StateBase();
	
	virtual void update(const float delta_time) = 0;
	virtual void render() = 0;

	void exit();

private:
	std::vector<sf::Texture> textures_;
	sf::RenderWindow* render_window_;
};

