#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <SFML/Graphics.hpp>
#include <stack>

#include "GameState.hpp"

class StateManager
{
private:
	std::stack<GameState*> states;

public:
	void addState(GameState* state);
	void loop();
	void render(sf::RenderWindow* window);
	void keyPressed(int code);
	void keyReleased(int code);
};

void StateManager::addState(GameState* state)
{
	states.push(state);
	states.top()->init();
}

void StateManager::loop()
{
	states.top()->loop();
}

void StateManager::render(sf::RenderWindow* window)
{
	states.top()->render(window);
}

void StateManager::keyPressed(int code)
{
	states.top()->keyPressed(code);
}

void StateManager::keyReleased(int code)
{
	states.top()->keyReleased(code);
}

#endif