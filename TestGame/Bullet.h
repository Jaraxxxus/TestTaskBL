
#pragma once
#include "Entity.h"
#include <windows.h>


class bullet : public entity
{
public:

	int timer;  // prevents bullets from getting into an infinite loop
	bullet( float _x, float _y, float _angle, std::string _name);
	void  update();
	
private:
	

};
