#include "BoxxleGameLevelRoom.h"
#include "MainMenuBackground.h"
#include "MainMenuRoom.h"
#include "SFMLButton.h"
#include "SFMLGame.h"

void QuitGame()
{
	SFMLGame::GetInstance()->QuitGame();
}

void PlayLevel001()
{
	SFMLGame::GetInstance()->GetCurrentRoom()->ChangeRoom(new BoxxleGameLevelRoom("Level_001_SFMLPort.txt", 1));
}

void PlayLevel002()
{
	SFMLGame::GetInstance()->GetCurrentRoom()->ChangeRoom(new BoxxleGameLevelRoom("", 1)); //put level two in between quotes
}

void PlayLevel003()
{
	SFMLGame::GetInstance()->GetCurrentRoom()->ChangeRoom(new BoxxleGameLevelRoom("", 1)); //put level three in between quotes
}

MainMenuRoom::MainMenuRoom()	//for some reason buttons clicked right above also light up...double check part 14 vid
	: SFMLRoom()
{
	InstanceCreate(new MainMenuBackground(0, 0));
	
	InstanceCreate(new SFMLButton(720, 510, "main_menu_button", QuitGame, "QUIT GAME", sf::Color::Black, sf::Color(0, 0, 0)));	//QUIT GAME
	InstanceCreate(new SFMLButton(60, 190, "main_menu_button", PlayLevel001, "LEVEL 1", sf::Color::Black, sf::Color(0, 0, 0)));	//LEVEL 1
	InstanceCreate(new SFMLButton(60, 350, "main_menu_button", PlayLevel002, "LEVEL 2", sf::Color::Black, sf::Color(0, 0, 0)));	//LEVEL 2
	InstanceCreate(new SFMLButton(60, 510, "main_menu_button", PlayLevel003, "LEVEL 3", sf::Color::Black, sf::Color(0, 0, 0)));	//LEVEL 3
}
