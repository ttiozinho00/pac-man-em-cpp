#ifndef PACMAN_H
#define PACMAN_H

#include "Directions.hpp"
#include "Entity.hpp"

#include <queue>


class PacMan
	: public Entity
{
private:
	std::queue<Direction> directions;
	int eatenDots;
	bool dead;

public:
	PacMan();

	void queueDirection(Direction dir);
	void move();
	std::queue<Direction> getDirections();
	void stop();

	void eatDot();
	int getDotsEaten();

	void setDead(bool d);
	bool isDead();
};

PacMan::PacMan() : Entity(13, 26)
{
	eatenDots = 0;
}

void PacMan::queueDirection(Direction dir)
{
	if (!directions.empty())
	{
		if (dir == -directions.front())
		{
			std::queue<Direction> clear;
			std::swap(directions, clear);
		}
	}

	if(directions.size() < 2)
		directions.push(dir);
}

void PacMan::move()
{
	if (!directions.empty())
	{
		switch (directions.front())
		{
			case Direction::Up:
				Entity::move(0, -0.4f);
				break;
			case Direction::Down:
				Entity::move(0, 0.4f);
				break;
			case Direction::Left:
				Entity::move(-0.4f, 0);
				break;
			case Direction::Right:
				Entity::move(0.4f, 0);
				break;
			default:
				break;	
		}
	}
}

std::queue<Direction> PacMan::getDirections()
{
	return directions;
}

void PacMan::stop()
{
	if (directions.size() > 1)
	{
		if ((int)(screenPosX + 8) % 16 == 0 && (int)(screenPosY + 8) % 16 == 0)
		{
			switch (directions.front())
			{
				case Direction::Up:
					directions.pop();
					break;
				case Direction::Down:
					directions.pop();
					break;
				case Direction::Left:
					directions.pop();
					break;
				case Direction::Right:
					directions.pop();
					break;
				default:
					break;	
			}
		}
	}
}

void PacMan::eatDot()
{
	eatenDots++;
}

int PacMan::getDotsEaten()
{
	return eatenDots;
}

void PacMan::setDead(bool d)
{
	dead = d;
}

bool PacMan::isDead()
{
	return dead;
}

#endif