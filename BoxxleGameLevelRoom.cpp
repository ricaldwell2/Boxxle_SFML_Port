#include <fstream>
#include <string>
#include "Box.h"
#include "Goal.h"
#include "Hero.h"
#include "Wall.h"
#include "MainMenuBackground.h"
#include "MainMenuRoom.h"
#include "BoxxleGameLevelRoom.h"
#include "SFMLButton.h"
#include "SFMLGame.h"

void ReturnToMainMenu()
{
	SFMLGame::GetInstance()->ChangeRoom(new MainMenuRoom());
}

BoxxleGameLevelRoom::BoxxleGameLevelRoom(const std::string& filename,
										 int levelNumber)
	: SFMLRoom(),
	  LevelNumber(levelNumber)
{
	std::ifstream file(filename); 
	if (file.fail())
	{
		throw std::exception("Text file not available for loading.");
	}
	
	while (file.eof() == false)
	{
		std::string name;
		float x;
		float y;
		file >> name >> x >> y;
		if (name == "Box")
		{
			InstanceCreate(new Box(x, y));
		}
		else if (name == "Wall")
		{
			InstanceCreate(new Wall(x, y));
		}
		else if (name == "Hero")
		{
			InstanceCreate(new Hero(x, y));
		}
		else if (name == "Goal")
		{
			InstanceCreate(new Goal(x, y));
		}
	}
	//should but gameplay_button within the SFMLButton function
	SFMLButton* button = new SFMLButton(0, 570, "main_menu_button", ReturnToMainMenu, "MAIN MENU", sf::Color::Yellow, sf::Color(128, 128, 128));
	button->SetDepth(4);
	InstanceCreate(button);

	file.close();
}