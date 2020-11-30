#ifndef GHOST_H
#define GHOST_H

#include "Entity.hpp"
#include "Directions.hpp"

class Ghost :
	public Entity
{
private:
	int destinationTileX;
	int destinationTileY;
	Direction moving;

	bool scattering;
	bool outOfCage;

	bool decision;

	int frightened;

public:
	Ghost(int tilePosX, int tilePosY, int destinationX, int destinationY);

	void setDestination(int x, int y);
	int getDestX();
	int getDestY();

	void setDirection(Direction dir);
	Direction getDirection();
	void move();

	bool isScattering();
	void setScattering(bool s);
	
	bool isOutOfCage();

	bool shouldTakeDecision();
	void setTakeDecision(bool d);

	void teleport(int x, int y);

	void setFrightened(bool f);
	bool isFrightened();
};

Ghost::Ghost(int tilePosX, int tilePosY, int destinationX, int destinationY) : Entity(tilePosX, tilePosY)
{
	setDestination(destinationX, destinationY);
	setDirection(Direction::Unset);
	scattering = true;
	outOfCage = false;
	decision = true;
	frightened = false;
}

void Ghost::setDestination(int x, int y)
{
	destinationTileX = x;
	destinationTileY = y;
}

int Ghost::getDestX()
{
	return destinationTileX;
}

int Ghost::getDestY()
{
	return destinationTileY;
}

void Ghost::setDirection(Direction dir)
{
	moving = dir;
}

Direction Ghost::getDirection()
{
	return moving;
}

void Ghost::move()
{
	switch (moving)
	{
	case Direction::Up:
		Entity::move(0, -0.2f);
		break;
	case Direction::Down:
		Entity::move(0, 0.2f);
		break;
	case Direction::Left:
		Entity::move(-0.2f, 0);
		break;
	case Direction::Right:
		Entity::move(0.2f, 0);
		break;

	default:
		break;	
	}
}

bool Ghost::isScattering()
{
	return scattering;
}

void Ghost::setScattering(bool s)
{
	scattering = s;
}

bool Ghost::isOutOfCage()
{
	return outOfCage;
}

bool Ghost::shouldTakeDecision()
{
	return decision;
}

void Ghost::setTakeDecision(bool d)
{
	decision = d;
}

void Ghost::teleport(int x, int y)
{
	Entity::teleport(x, y);
	outOfCage = true;
}

void Ghost::setFrightened(bool f)
{
	if (f)
	{
		frightened = 2000;
	}

	else
	{
		frightened = 0;
	}
}

bool Ghost::isFrightened()
{
	if (frightened > 0)
	{
		frightened--;
	} 
	return frightened > 0;
}

#endif
