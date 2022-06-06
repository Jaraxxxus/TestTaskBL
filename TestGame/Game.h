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
	sf::Font font;//רנטפע 

	void run();
	
private:
	unit* p = nullptr;
	unit* e = nullptr;

	std::list<entity*> entities;
	

};

