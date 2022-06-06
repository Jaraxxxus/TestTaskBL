#pragma once
#include "Entity.h"
#include "Bullet.h"
#include "Unit.h"
#include "Wall.h"
#include <list>
#include <iostream>
#include "windows.h"


const double RADTODEG = 180 / 3.14159265;


class mechanic {

public:
	
	mechanic(unit* a, unit* b, std::list<entity*>& entities);
	void tick(std::list<entity*>& entities);
	std::string getScore();
	
private:
	unit* p;  //player ptr
	unit* e;  //enemy ptr
	int advantage = 0; // additional time the enemy waits before shoot 
	int deathP = 0; //player death count

	int deathE = 0;//npc  death count

	void input(std::list<entity*>& entities); 

	void restart(std::list<entity*>& entities);
	
	void Collision(bullet& b, wall& w);

	void Collision(bullet& b, unit& u);
	
	void Collision(wall& w, unit& u);
	
	void ENlogic(std::list<entity*>& entities); //enemy logic
		
};

