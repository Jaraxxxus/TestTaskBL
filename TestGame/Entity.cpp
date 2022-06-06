#include "Entity.h"






entity::entity(std::string textureName, float x, float y) {
	texture.loadFromFile(textureName);
	sprite.setTexture(texture);
	this->x = x;
	this->y = y;
	width = texture.getSize().x;
	height = texture.getSize().y;
	sprite.setOrigin(width / 2, height / 2);
	dx = dy = 0;
	
	
}

/*
void entity::draw(sf::RenderWindow& app) {
	sprite.setPosition(x, y);
	sprite.setRotation(angle);
	app.draw(sprite);
}
*/

entity::~entity() {

}

sf::Sprite entity::getSprite() {
	return sprite;
}

void entity::setTexture(std::string _t) {
	texture.loadFromFile(_t);
	sprite.setTexture(texture);
	width = texture.getSize().x;
	height = texture.getSize().y;
}

void entity::update() {

}


 void entity::setPosition(float _x, float _y) {
	x = _x; y = _y;
}
  
sf::FloatRect  entity::getRect() {
	return sf::FloatRect(x - width / 2, y - height / 2, width, height);
}




