#pragma once
#include "Entity.h"
#include "Bullet.h"
#include "Unit.h"
#include "Wall.h"
#include <list>
#include <iostream>
#include "windows.h"


const float RADTODEG = 180 / 3.14159265;


class mechanic {

public:
	
	mechanic(unit* a, unit* b, std::list<entity*>& entities);
	void tick(std::list<entity*>& entities);
	std::string getScore();
	
private:
	unit* p;
	unit* e;
	int advantage = 0;
	int deathP = 0;

	int deathE = 0;

	void input(std::list<entity*>& entities);

	void restart(std::list<entity*>& entities);
	
	void Collision(bullet& b, wall& w);

	void Collision(bullet& b, unit& u);
	
	void Collision(wall& w, unit& u);
	
	void ENlogic(std::list<entity*>& entities);
		
};

