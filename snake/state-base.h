#ifndef STATE_H
#define STATE_H

#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

using namespace sf;
using namespace std;

class StateBase
{
private:
	vector<Texture> m_textures;

public:
	StateBase();
	virtual ~StateBase();

	virtual void update() = 0;
	virtual void render() = 0;

};

#endif

