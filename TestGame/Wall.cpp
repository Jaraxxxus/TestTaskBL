#include "Wall.h"


wall::wall(float x1, float y1)
{
	name = "Wall";
	x = x1;
	y = y1;

	texture.loadFromFile("Images/Wall.png");
	width = texture.getSize().x;
	height = texture.getSize().y;
	sprite.setTexture(texture);
	sprite.setOrigin(sf::Vector2f(texture.getSize()) / 2.f);
	sprite.setPosition(x, y);
}


wall::~wall()  {};
void wall::update() {};

void wall::rotate(float _angle)
{
	angle += _angle;
	norm_x = { cos(angle * DEGTORAD), sin(angle * DEGTORAD) };
	norm_y[0] = norm_x[1];
	norm_y[1] = norm_x[0];
}