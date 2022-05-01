#pragma once

#include <SFML/Graphics.hpp>

class SFMLKeyboard 
{
public:
	static SFMLKeyboard* GetInstance();

	bool IsKeyUp(sf::Keyboard::Key Key);
	bool IsKeyPressed(sf::Keyboard::Key Key);
	bool IsKeyDown(sf::Keyboard::Key Key);
	bool IsKeyReleased(sf::Keyboard::Key Key);

	void Update();

private:
	SFMLKeyboard();
	
	static SFMLKeyboard* Instance;

	bool Current[125];			//125 comes from number of buttons on a keyboard
	bool Previous[125];			//125 comes from number of buttons on a keyboard
};