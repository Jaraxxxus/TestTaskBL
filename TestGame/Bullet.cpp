#include "Bullet.h"




bullet::bullet(float _x, float _y, float _angle, std::string _name) {
	
	
	angle = _angle;
	name = _name;
	isDead = false;
	if (name == "BlueBullet")
	setTexture("Images/Bbullet.png");
	if (name == "RedBullet")
		setTexture("Images/Rbullet.png");
	sprite.setOrigin(sf::Vector2f(texture.getSize()) / 2.f);
	sprite.setPosition(x, y);
	dx = (float)cos(angle * DEGTORAD) * 2.7;
	dy = (float)sin(angle * DEGTORAD) * 2.7;

	timer = 12;
	x = _x + 8*dx;
	y = _y + 8*dy;
}



void  bullet::update()

{
	std::cout << timer << std::endl;

	
	
	if (!timer)
		isDead = true;
	
	x += dx;
	y += dy;



	if (x > windowWidth || x < 0 || y > windowHeight || y < 0) isDead = true;
	sprite.setPosition(x, y);


}
