#include "Unit.h"


unit::unit(std::string textureName, float x, float y)
{
	
	texture.loadFromFile(textureName);
	sprite.setTexture(texture);
	this->x = x;
	this->y = y;
	width = texture.getSize().x;
	height = texture.getSize().y;
	

	sprite.setOrigin(sf::Vector2f(texture.getSize()) / 2.f);
	dx = dy = 0;
}

bullet *unit::shoot() 
{	
	bullet* b = new bullet(this->x , this->y, this->angle, bulletName);

	reloadTime = 80;

	return b;

}
unit::~unit() {};

void unit::update() 
{
	if (reloadTime > 0)
		--reloadTime;

	if (thrust)
	{
		dx = cos(angle * DEGTORAD) * 0.7 * thrust;
		dy = sin(angle * DEGTORAD) * 0.7 * thrust;
	}
	else
	{
		dx *= 0.99;
		dy *= 0.99;
	}

	x += dx;
	y += dy;


	checkBorder();
	sprite.setPosition(x, y);
	sprite.setRotation(angle+90);
	
}

void unit::setBname(std::string s)
{
	bulletName = s;
}

void unit::checkBorder()
{

	if (x > windowWidth) {
		x -= dx;
		dx = -dx;

	};
	if (x < 0)
	{
		x -= dx;
		dx = -dx;

	}


	if (y > windowHeight)
	{
		y -= dy;
		dy = -dy;

	}
	if (y < 0)
	{
		y -= dy;
		dy = -dy;

	}
}

bool unit::isReload()
{
	if (reloadTime < 1)
		return true;
	return false;
}

