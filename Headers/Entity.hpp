#ifndef ENTITY_H
#define ENTITY_H

#include <cmath>

class Entity
{
protected:
	float screenPosX;
	float screenPosY;
	int tileX;
	int tileY;

public:
	Entity(int tilePosX, int tilePosY);

	float getScreenPosX();
	float getScreenPosY();
	int getTileX();
	int getTileY();

	void move(float x, float y);
	void teleport(int x, int y);
};

Entity::Entity(int tilePosX, int tilePosY)
{
	tileX = tilePosX;
	tileY = tilePosY;
	screenPosX = tilePosX * 16.0f + 8.0f + 8.0f;
	screenPosY = tilePosY * 16.0f + 8.0f;
}

float Entity::getScreenPosX()
{
	return screenPosX;
}

float Entity::getScreenPosY()
{
	return screenPosY;
}

int Entity::getTileX()
{
	return tileX;
}

int Entity::getTileY()
{
	return tileY;
}

void Entity::move(float x, float y)
{
	screenPosX += x;
	screenPosY += y;

	if ((int)(screenPosX + 8) % 16 == 0 && (int)(screenPosY + 8) % 16 == 0)
	{
		tileX = (int) round((screenPosX - 8) / 16);
		tileY = (int) round((screenPosY - 8) / 16);
	}
}

void Entity::teleport(int x, int y)
{
	tileX = x;
	tileY = y;
	screenPosX = x * 16.0f + 8.0f;
	screenPosY = y * 16.0f + 8.0f;
}

#endif