
#pragma once
#include "Entity.h"
#include <windows.h>


class bullet : public entity
{
public:

	int timer;
	bullet( float _x, float _y, float _angle, std::string _name);
	
	void  update();
	
private:
	

};
