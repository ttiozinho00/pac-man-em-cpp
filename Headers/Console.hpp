#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>

using namespace std;

class Console
{
private:
	std::string m_name;

public:
	Console(std::string name);
	void writeLine(std::string line);
};

Console::Console(string name)
{
	m_name = name;
}

void Console::writeLine(string line)
{
	cout << "[" << m_name << "]: " << line << endl;
}

#endif