#include "MainMenuRoom.h"
#include "GameInitializationRoom.h"
#include "SFMLTextureManager.h"

GameInitializationRoom::GameInitializationRoom()
{
	//Engine level sprite memory allocation
	SFMLTextureManager::GetInstance()->AddTexture("basic_font", "basic_font.png");

	//Game level sprite memory allocations
	SFMLTextureManager::GetInstance()->AddTexture("main_menu_background", "Main_Menu.png");
	SFMLTextureManager::GetInstance()->AddTexture("main_menu_button", "Main_Menu_Button.png");

	//Come back to part 16 @ about 45:00 to see gameplay button (entirely different sprite)
	SFMLTextureManager::GetInstance()->AddTexture("gameplay_button", "gameplay_button.png");

	//Put in all sprite memory allocation and initialization here
	SFMLTextureManager::GetInstance()->AddTexture("hero_left", "hero_left.png");
	SFMLTextureManager::GetInstance()->AddTexture("hero_right", "hero_right.png");
	SFMLTextureManager::GetInstance()->AddTexture("hero_up", "hero_up.png");
	SFMLTextureManager::GetInstance()->AddTexture("hero_down", "hero_down.png");
	SFMLTextureManager::GetInstance()->AddTexture("box", "box.png");
	SFMLTextureManager::GetInstance()->AddTexture("goal", "goal.png");
	SFMLTextureManager::GetInstance()->AddTexture("wall", "wall.png");
}

void GameInitializationRoom::Step()
{
	//What is the first "real" room of my game!
	ChangeRoom(new MainMenuRoom());
}
