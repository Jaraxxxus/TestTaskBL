#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Bullet.h"
#include "Unit.h"
#include "Wall.h"
#include <list>
#include <iostream>
#include "windows.h"
#include "mechanic.h"



class Game  {

public:
	const int windowWidth = 800;
	const int windowHeight = 800;
	sf::Font font; 

	void run();
	~Game();
private:
	unit* p = nullptr;  //player ptr
	unit* e = nullptr;  // enemy ptr

	std::list<entity*> entities; 
	

};

