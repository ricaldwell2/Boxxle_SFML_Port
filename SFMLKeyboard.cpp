#include "SFMLKeyboard.h"

SFMLKeyboard* SFMLKeyboard::Instance = nullptr;

SFMLKeyboard::SFMLKeyboard()
{
	Update();
}

SFMLKeyboard* SFMLKeyboard::GetInstance()
{
	if (Instance == nullptr)
	{
		Instance = new SFMLKeyboard();
	}

	return Instance; 
}

bool SFMLKeyboard::IsKeyUp(sf::Keyboard::Key Key)
{
	return (Current[Key] == false) && (Previous[Key] == false);
}

bool SFMLKeyboard::IsKeyPressed(sf::Keyboard::Key Key)
{
	return (Current[Key] == true) && (Previous[Key] == false);
}

bool SFMLKeyboard::IsKeyDown(sf::Keyboard::Key Key)
{
	return (Current[Key] == true) && (Previous[Key] == true);
}

bool SFMLKeyboard::IsKeyReleased(sf::Keyboard::Key Key)
{
	return (Current[Key] == false) && (Previous[Key] == true);
}

void SFMLKeyboard::Update()
{
	for (int i = 0; i < sf::Keyboard::KeyCount; ++i)
	{
		Previous[i] = Current[i];
		Current[i] = sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i));
	}
}
