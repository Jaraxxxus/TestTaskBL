
#pragma once

#include <string>

#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>



class entity
{
public:
	const float DEGTORAD = 0.017453f;  //for degree to radian
	std::string name;
	float angle = 0;
	
	
	float x;
	float y;
	float dx, dy;
	int height, width;
	bool isDead = false;
	
	

	entity() = default;
	entity(std::string textureName, float x, float y);
	//virtual void draw(sf::RenderWindow& app);
	virtual ~entity();

	virtual sf::Sprite getSprite();
	virtual void setTexture(std::string _t);
	virtual void update();
	virtual void setPosition(float _x, float _y);
	virtual  sf::FloatRect getRect(); //creates a sprite based rectangle
	

protected:
	sf::Texture texture;
	sf::Sprite sprite;
	
	const int windowWidth = 800;
	const int windowHeight = 800;

};












