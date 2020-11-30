#ifndef RESOURCES_H
#define RESOURCES_H

#include <SFML/Graphics.hpp>
#include <map>

#include "Directions.hpp"
#include "Animation.hpp"
#include "Console.hpp"

class Resources
{
private:
	static sf::Texture Things;
	static sf::Texture Labyrinth;
	static Console Console;

	static std::map<int, sf::Sprite*> sprites;
	static std::map<int, Animation> animations;

	static void loadSprite(int value, int rect1, int rect2, int animationframes);

	static const int PacManDown;
	static const int PacManLeft;
	static const int PacManRight;
	static const int BlinkyDown;
	static const int BlinkyLeft;
	static const int BlinkyRight;
	static const int PinkyDown;
	static const int PinkyLeft;
	static const int PinkyRight;
	static const int InkyDown;
	static const int InkyLeft;
	static const int InkyRight;
	static const int ClydeDown;
	static const int ClydeLeft;
	static const int ClydeRight;

public:
	static void load();
	static sf::Sprite* get(int value, bool animated, Direction facing);

	static sf::Sprite* LabyrinthPieces[];

	static const int PacMan;
	static const int Blinky;
	static const int Pinky;
	static const int Inky;
	static const int Clyde;
	static const int FrightenedGhost;
	static const int DeadPacMan;
};

std::map<int, sf::Sprite*> Resources::sprites;
std::map<int, Animation> Resources::animations;

sf::Texture Resources::Things;
sf::Texture Resources::Labyrinth;
Console Resources::Console("Resources");

sf::Sprite* Resources::LabyrinthPieces[32];

const int Resources::PacMan = 0;
const int Resources::PacManDown = 1;
const int Resources::PacManLeft = 2;
const int Resources::PacManRight = 3;
const int Resources::Blinky = 4;
const int Resources::BlinkyDown = 5;
const int Resources::BlinkyLeft = 6;
const int Resources::BlinkyRight = 7;
const int Resources::Pinky = 8;
const int Resources::PinkyDown = 9;
const int Resources::PinkyLeft = 10;
const int Resources::PinkyRight = 11;
const int Resources::Inky = 12;
const int Resources::InkyDown = 13;
const int Resources::InkyLeft = 14;
const int Resources::InkyRight = 15;
const int Resources::Clyde = 16;
const int Resources::ClydeDown = 17;
const int Resources::ClydeLeft = 18;
const int Resources::ClydeRight = 19;
const int Resources::FrightenedGhost = 20;
const int Resources::DeadPacMan = 21;

void Resources::load()
{
	Labyrinth.loadFromFile("textures/labyrinth.png");

	int index = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			LabyrinthPieces[index] = new sf::Sprite(Labyrinth, sf::IntRect(i * 8, j * 8, 8, 8));
			LabyrinthPieces[index]->setScale(2.0f, 2.0f);
			index++;
		}
	}

	Things.loadFromFile("textures/things.png");

	loadSprite(Resources::PacMan, 0, 0, 3);
	loadSprite(Resources::PacManDown, 45, 0, 3);
	loadSprite(Resources::PacManLeft, 90, 0, 3);
	loadSprite(Resources::PacManRight, 135, 0, 3);
	loadSprite(Resources::Blinky, 0, 15, 2);
	loadSprite(Resources::BlinkyDown, 30, 15, 2);
	loadSprite(Resources::BlinkyLeft, 60, 15, 2);
	loadSprite(Resources::BlinkyRight, 90, 15, 2);
	loadSprite(Resources::Pinky, 0, 30, 2);
	loadSprite(Resources::PinkyDown, 30, 30, 2);
	loadSprite(Resources::PinkyLeft, 60, 30, 2);
	loadSprite(Resources::PinkyRight, 90, 30, 2);
	loadSprite(Resources::Inky, 0, 45, 2);
	loadSprite(Resources::InkyDown, 30, 45, 2);
	loadSprite(Resources::InkyLeft, 60, 45, 2);
	loadSprite(Resources::InkyRight, 90, 45, 2);
	loadSprite(Resources::Clyde, 0, 60, 2);
	loadSprite(Resources::ClydeDown, 30, 60, 2);
	loadSprite(Resources::ClydeLeft, 60, 60, 2);
	loadSprite(Resources::ClydeRight, 90, 60, 2);
	loadSprite(Resources::FrightenedGhost, 120, 15, 2);
	loadSprite(Resources::DeadPacMan, 0, 75, 12);

	Console.writeLine("Finished creating sprites");
}

sf::Sprite* Resources::get(int value, bool animated, Direction facing)
{
	if (value != Resources::FrightenedGhost)
	{
		switch (facing)
		{
			case Direction::Down:
				value += 1;
				break;
			case Direction::Left:
				value += 2;
				break;
			case Direction::Right:
				value += 3;
				break;
			default:
				break;	
		}
	}

	if (animated)
	{
		animations.at(value).changeFrame();
		sprites.at(value)->setTextureRect(animations.at(value).getBounds());
	}

	return sprites.at(value);
}


void Resources::loadSprite(int value, int rect1, int rect2, int animationframes)
{
	sf::IntRect* rect = new sf::IntRect(rect1, rect2, 15, 15);
	sf::Sprite* sprite = new sf::Sprite(Things, *rect);
	sprite->setScale(2.0f, 2.0f);
	sprite->setOrigin(7.5f, 7.5f);
	sprites.insert(std::pair<int, sf::Sprite*>(value, sprite));
	animations.insert(std::pair<int, Animation>(value, Animation(rect, animationframes)));
}

#endif