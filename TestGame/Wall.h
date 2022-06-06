
#pragma once
#include "Entity.h"

class wall :public entity
{
public:
	wall(float x1, float y1);
	~wall() override;
	void update() override;
	void rotate(float _angle);
	
private:
	std::vector<float> norm_x = {0, 1};
	std::vector<float> norm_y = {1, 0};
}; 