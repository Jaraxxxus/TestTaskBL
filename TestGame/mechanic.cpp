#include "mechanic.h"


mechanic::mechanic(unit* a, unit* b, std::list<entity*>& entities)
{
	p = a;
	e = b;
	p = new unit("Images/Player.png", 500, 700);
	e = new unit("Images/Enemy.png", 200, 200);
	p->setBname("BlueBullet");
	e->setBname("RedBullet");
	e->name = "Enemy";
	p->name = "Player";
	restart(entities);
}


void mechanic::tick(std::list<entity*>& entities)
{


	input(entities);    
	ENlogic(entities); //enemy move 
	p->update();
	e->update();
	
	for (auto a : entities)
	{

		a->update();
		for (auto b : entities)
		{
			if ((a->name == "BlueBullet" || a->name == "RedBullet") && (b->name == "BlueBullet" || b->name == "RedBullet"))
				continue; // if a & b is bullet
			if (a->getRect().intersects(b->getRect())) // if a & b intersects
			{
				if ((a->name == "Player" || a->name == "Enemy") && b->name == "Wall")
				{

					Collision(*((wall*)b), *((unit*)a));
				}
				if (a->name == "Player" && b->name == "RedBullet")
				{

					Collision(*((bullet*)b), *((unit*)a));
				}
				if (a->name == "Enemy" && b->name == "BlueBullet")
				{

					Collision(*((bullet*)b), *((unit*)a));
				}
				if ((a->name == "BlueBullet" || a->name == "RedBullet") && b->name == "Wall")
				{

					Collision(*((bullet*)a), *((wall*)b));
				}

			}

		}

	}
	//delete bullets that crossed the border
	auto it = entities.begin();
	while (it != entities.end() && !entities.empty())
	{

		if ((*it)->isDead && ((*it)->name == "BlueBullet" || (*it)->name == "RedBullet"))
		{
			delete (*it);
			it = entities.erase(it);
		}
		else
			it++;

	}


	if (p->isDead)
	{
		
		deathP++;
		restart(entities);
		
	}
	if (e->isDead)
	{

		deathE++;
		restart(entities);
	}

}


std::string mechanic::getScore()
{
	std::string str = "score ";
	str += std::to_string(deathE) + " : " + std::to_string(deathP);;

	return str;
}


void mechanic::input(std::list<entity*>& entities)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space )&& p->isReload()) {
		entities.push_back(p->shoot());
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) p->angle += 3;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  p->angle -= 3;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) 	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) p->thrust = 1;
		else p->thrust = -1;
	} 
	else p->thrust = 0;
}


void mechanic::restart(std::list<entity*>& entities)
{
	auto it = entities.begin();
	advance(it, 2);
	//memory clearing
	while (it != entities.end() && !entities.empty())
	{
			delete (*it);
			it = entities.erase(it);
	}


	entities.clear();
	p->setPosition(500, 600);
	e->setPosition(200, 200);
	e->angle = 200;
	p->angle = 33;
	p->isDead = false;
	e->isDead = false;
	entities.push_back(p);
	entities.push_back(e);
	entities.push_back(new wall(700, 700));
	entities.push_back(new wall(100, 700));
	entities.push_back(new wall(50, 150));
	entities.push_back(new wall(450, 100));
	entities.push_back(new wall(550, 100));
	advantage = 0;
}

//ricochet
void mechanic::Collision(bullet& b, wall& w){
	b.timer--;
	b.x -= 2.5 * b.dx;
	b.y -= 2.5 * b.dy;
	double Dx = b.x - w.x;
	double Dy = b.y - w.y;
	double d = sqrt(Dx * Dx + Dy * Dy);      if (d == 0) d = 0.01;                 // to avoid division by 0
	double ax = Dx / d;
	double ay = Dy / d;

	double Vn1 = w.dx * ax + w.dy * ay;
	double Vn2 = b.dx * ax + b.dy * ay;


	Dx = b.x - w.x;
	Dy = b.y - w.y;
	d = sqrt(Dx * Dx + Dy * Dy);  if (d == 0) d = 0.01;
	ax = Dx / d;
	ay = Dy / d;


	Vn1 = w.dx * ax + w.dy * ay;
	Vn2 = b.dx * ax + b.dy * ay;

	double Vt2 = -b.dx * ay + b.dy * ax;

	Vn2 = Vn1 - Vn2;

	b.dx = Vn2 * ax - Vt2 * ay;
	b.dy = Vn2 * ay + Vt2 * ax;

}


void mechanic::Collision(bullet& b, unit& u) {
	
	b.isDead = true;
	u.isDead = true;


}

void mechanic::Collision(wall& w, unit& u) {

	

	if (u.x < w.x)
	{

		u.x -= 3 * u.dx;

	}
	if (u.x > w.x)
	{
		u.x -= 3 * u.dx;

	}

	if (u.y < w.y)
	{
		u.y -= 3 * u.dy;

	}
	if (u.y > w.y)
	{
		u.y -= 3 * u.dy;

	}

}

void mechanic::ENlogic(std::list<entity*>& entities) {
	if (e->isReload()) //to slow down the shooting
		advantage++;

	float Dx = e->x - p->x;
	float Dy = e->y - p->y;

	//rotate to player


	float rotation = (atan2(Dy, Dx)) * RADTODEG - e->angle + 180;
	if (rotation > 361)
		rotation -= 360;
	if (rotation < -180)
		rotation += 180;
	if (rotation > 0 && rotation < 180) {
		e->angle += 3;
	}
	else if (rotation < 360 && rotation >  180 || rotation < 0) {
		e->angle -= 3;
	}
	if ((rotation <10 && rotation>-10  || rotation < 365 && rotation>355) && advantage >=50)
	{

		entities.push_back(e->shoot());

		advantage = 0;
	}






	//keeps the distance
	int oldThrust = 0;

	float d = sqrt(Dx * Dx + Dy * Dy); if (d == 0) d = 0.01;

	
	if (d <= 225 && d >= 200 || d <= 290 && d >= 275) {
		oldThrust = e->thrust;
	}
	
	if (d < 200) {

		if (oldThrust < 0)
			e->thrust = 1;
		else
			e->thrust = -1;
	} else 	if (d > 270) {

		if (oldThrust >= 0)
			e->thrust = 1;
		else
			e->thrust = -1;
	} 
	else e->thrust = 0;


}


