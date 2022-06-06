
#pragma once

#include "Bullet.h"

class unit : public entity
{
public:
	int thrust = 0;
	unit(std::string textureName, float x, float y);
	bullet* shoot();
	~unit();
	void update() override;
	void setBname(std::string s);//	name of the bullet, responsible for its texture and friendlyfire
	bool isReload();
private:
	std::string bulletName; //bullets get this name
	int reloadTime = 0;
	
	void checkBorder();
	
};

