#include "SFMLGame.h"
#include "SFMLMouse.h"

SFMLMouse* SFMLMouse::Instance = nullptr;

SFMLMouse::SFMLMouse()
{
	Update();
}

SFMLMouse* SFMLMouse::GetInstance() 
{
	if (Instance == nullptr)
	{
		Instance = new SFMLMouse();
	}

	return Instance;
}

sf::Vector2i SFMLMouse::GetMousePosition()
{
	return sf::Mouse::getPosition(*SFMLGame::GetInstance()->GetWindow());
}

bool SFMLMouse::IsButtonUp(sf::Mouse::Button Button)
{
	return (Current[Button] == false) && (Previous[Button] == false);
}

bool SFMLMouse::IsButtonPressed(sf::Mouse::Button Button)
{
	return (Current[Button] == true) && (Previous[Button] == false);
}

bool SFMLMouse::IsButtonDown(sf::Mouse::Button Button)
{
	return (Current[Button] == true) && (Previous[Button] == true);
}

bool SFMLMouse::IsButtonReleased(sf::Mouse::Button Button)
{
	return (Current[Button] == false) && (Previous[Button] == true);
}

void SFMLMouse::Update()
{
	for (int i = 0; i < sf::Mouse::ButtonCount; ++i)
	{
		Previous[i] = Current[i];
		Current[i] = sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(i));
	}
}
