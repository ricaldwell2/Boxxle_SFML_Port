//This project is my first dive into SFML creating Boxxle.

#include <iostream>
#include "SFMLGame.h"

int main()
{
	
	SFMLGame::GetInstance()->SetFPS(10);
	//SFMLGame::GetInstance()->SetWindowResolution(1280, 720);
	//SFMLGame::GetInstance()->SetTitleBarText("Hello Text Bar!");
	
	SFMLGame::GetInstance()->Run();
	return 0;
}