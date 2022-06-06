
#pragma once

#include "Bullet.h"

class unit : public entity
{
public:
	unit(std::string textureName, float x, float y);
	bullet* shoot();
	~unit();
	void update() override;
	void setBname(std::string s);
	bool isReload();
private:
	std::string bulletName;
	int reloadTime = 0;
	float oldangle = 0;
	void checkBorder();
	
};

