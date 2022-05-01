#include <iostream>
#include "GameInitializationRoom.h"
#include "SFMLGame.h"
#include "SFMLKeyboard.h"
#include "SFMLMouse.h"

SFMLGame* SFMLGame::Instance = nullptr;

SFMLGame::SFMLGame()
	: FramesPerSecond(60.0f),		//60 fps is standard
	  WindowWidth(1280),
	  WindowHeight(720),
	  TitleBarText("Riley Caldwell (C)opyright 2022"),
	  Window(new sf::RenderWindow(sf::VideoMode(WindowWidth, WindowHeight), TitleBarText)),
	  TimePerFrame(sf::seconds(1.0f / FramesPerSecond)),
	  CurrentRoom(new GameInitializationRoom()),
	  NextRoom(nullptr)
{
	//Nothing here...
}

void SFMLGame::PossiblyChangeRoom()
{
	if (NextRoom != nullptr)
	{
		delete CurrentRoom;
		CurrentRoom = NextRoom;
		NextRoom = nullptr;
	}
}

SFMLGame::~SFMLGame()
{
	delete Window;
}

void SFMLGame::ProcessEvents()
{
	sf::Event event;
	while (Window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			Window->close();
		}
	}
}

void SFMLGame::Draw()
{
	Window->clear();
	CurrentRoom->Draw();
	Window->display();
}

void SFMLGame::Step()
{
	CurrentRoom->Step();
}

void SFMLGame::Run()
{
	//Game Loop
	sf::Clock Clock;
	sf::Time TimeSinceLastUpdate = sf::Time::Zero;
	
	while (Window->isOpen())
	{
		TimeSinceLastUpdate += Clock.restart();
		ProcessEvents();
		while (TimeSinceLastUpdate > TimePerFrame)
		{
			SFMLKeyboard::GetInstance()->Update();
			SFMLMouse::GetInstance()->Update();
			TimeSinceLastUpdate -= TimePerFrame;
			Step();
			ProcessEvents();
			std::cout << '.';
		}
		Draw();
		PossiblyChangeRoom();
	}
}

sf::RenderWindow* SFMLGame::GetWindow()
{
	return Window;
}

SFMLRoom* SFMLGame::GetCurrentRoom() 
{
	return CurrentRoom;
}

void SFMLGame::ChangeRoom(SFMLRoom* NewRoom)
{
	if (NextRoom == nullptr)
	{
		NextRoom = NewRoom;
	}
	else 
	{
		delete NewRoom;
	}
}

SFMLGame* SFMLGame::GetInstance()
{
	if (Instance == nullptr)
	{
		Instance = new SFMLGame();
	}
	return Instance;
}

float SFMLGame::GetFPS()
{
	return FramesPerSecond;
}

void SFMLGame::SetFPS(float fps)
{
	FramesPerSecond = fps;
	TimePerFrame = sf::seconds(1.0f / FramesPerSecond);
}

void SFMLGame::SetWindowResolution(int width, int height)
{
	delete Window;
	WindowWidth = width;
	WindowHeight = height;
	Window = new sf::RenderWindow(sf::VideoMode(WindowWidth, WindowHeight), TitleBarText);
}

sf::Vector2u SFMLGame::GetWindowResolution()
{
	return Window->getSize();
}

std::string SFMLGame::GetTitleBarText()
{
	return TitleBarText;
}

void SFMLGame::SetTitleBarText(const std::string& text)
{
	TitleBarText = text;
	Window->setTitle(TitleBarText);
}

void SFMLGame::QuitGame()
{
	exit(0);
}