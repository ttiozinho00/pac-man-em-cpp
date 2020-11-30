#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Animation
{
private:
	sf::IntRect* bounds;
	int frames;
	sf::Clock clock;
	int resetValue;

public:
	Animation(sf::IntRect* rect, int framesNumber);
	void changeFrame();
	sf::IntRect getBounds();
};

Animation::Animation(IntRect* rect, int framesNumber)
{
	bounds = rect;
	frames = framesNumber;
	resetValue = rect->left;
}

void Animation::changeFrame()
{
	if (clock.getElapsedTime().asSeconds() >= 0.1f)
	{
		if (bounds->left >= (resetValue + 15 * (frames-1)))
		{
			bounds->left = resetValue;
		}
		else
		{
			bounds->left += 15;
		}
		clock.restart();
	}
}

IntRect Animation::getBounds()
{
	return *bounds;
}

#endif