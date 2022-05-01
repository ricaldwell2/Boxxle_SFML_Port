#pragma once

//#include <string>
#include <SFML/Graphics.hpp>
#include "SFMLRoom.h"

class SFMLGame
{
public:
	~SFMLGame();
	void ProcessEvents();
	void Draw();
	void Step();
	void Run();
	static SFMLGame* GetInstance();
	
	sf::RenderWindow* GetWindow();

	//MODIFIED
	SFMLRoom* GetCurrentRoom();

	void ChangeRoom(SFMLRoom* NewRoom);

	float GetFPS();
	void SetFPS(float fps);

	void SetWindowResolution(int width, int height);
	sf::Vector2u GetWindowResolution();

	std::string GetTitleBarText();
	void SetTitleBarText(const std::string& text);

	void QuitGame();

private:
	SFMLGame();
	void PossiblyChangeRoom();

	float FramesPerSecond;
	int WindowWidth;
	int WindowHeight;
	std::string TitleBarText;
	sf::RenderWindow * Window;
	sf::Time TimePerFrame;
	SFMLRoom* CurrentRoom;
	SFMLRoom* NextRoom;

	static SFMLGame* Instance;
};