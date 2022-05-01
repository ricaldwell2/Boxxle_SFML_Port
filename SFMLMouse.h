#pragma once

#include <SFML/Graphics.hpp>

class SFMLMouse
{
public:
	static SFMLMouse* GetInstance();

	sf::Vector2i GetMousePosition();

	bool IsButtonUp(sf::Mouse::Button Button);
	bool IsButtonPressed(sf::Mouse::Button Button);
	bool IsButtonDown(sf::Mouse::Button Button);
	bool IsButtonReleased(sf::Mouse::Button Button);

	void Update();

private:
	SFMLMouse();

	static SFMLMouse* Instance;

	bool Current[5];
	bool Previous[5];
};