#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include "StateManager.hpp"
#include "PlayingState.hpp"
#include "Resources.hpp"
#include "Console.hpp"

using namespace sf;

class Engine
{
private:
	static sf::RenderWindow window;
	static Console console;
	static StateManager gamestates;

public:
	static void init();
	static bool isRunning();
	static void handleEvents();
	static void render();
};

RenderWindow Engine::window;
Console Engine::console("Engine");
StateManager Engine::gamestates;

void Engine::init()
{
	console.writeLine("Init...");
	Resources::load();
	window.create(VideoMode(448, 596), "PacMan Game");
	console.writeLine("Created window");
	gamestates.addState(new PlayingState);
}

bool Engine::isRunning()
{
	return window.isOpen();
}

void Engine::handleEvents()
{
	Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
			case Event::Closed:
				console.writeLine("Closing window...");
				window.close();
				break;
			case Event::KeyPressed:
				gamestates.keyPressed(event.key.code);
				break;
			case Event::KeyReleased:
				gamestates.keyReleased(event.key.code);
				break;
			default:
				break;	
		}
	}
	gamestates.loop();
}

void Engine::render()
{
	window.clear(Color::Black);
	gamestates.render(& window);
	window.display();
}

#endif