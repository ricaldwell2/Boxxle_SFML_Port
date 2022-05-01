#include "Hero.h"
#include "Goal.h"
#include "Box.h"
#include "MainMenuRoom.h"
#include "SFMLGame.h"
#include "SFMLKeyboard.h"
#include "SFMLTextureManager.h"
#include "SolidObject.h"

Hero::Hero(float x, float y)
	: SFMLObject(x, y, "hero_down", 4, 1), //last 2 nums...4 frames horizontally 1 vertically
	  Steps(0),
	  Font(new SFMLFont())
{
	//What should the character do when you start the level?
	SetDepth(3);
}

Hero::~Hero()
{
	delete Font;
}

void Hero::Step()
{
	SFMLObject::Step();		//Calling parent function plus the override stuff for the hero sprite

	if (SFMLKeyboard::GetInstance()->IsKeyDown(sf::Keyboard::Escape))//TODO: Get rid of this later...
	{
		SFMLGame::GetInstance()->GetCurrentRoom()->ChangeRoom(new MainMenuRoom()); //use this principle to reset room?
	}

	if (SFMLKeyboard::GetInstance()->IsKeyDown(sf::Keyboard::Right) && (Alarm(0) < 0))
	{
		std::vector<SolidObject*> solids = GetAllGameObjectsAtPosition<SolidObject *>(X() + SpriteWidth(), Y());
		if (solids.empty() == true)
		{
			SetImageSpeed(0.9f);
			SetSpeed(6);
			SetDirection(0);
			SetAlarm(0, 10);
			GetSprite()->setTexture(*SFMLTextureManager::GetInstance()->GetTexture("hero_right"));
		}
		else
		{
			std::vector<Box*> boxes = GetAllGameObjectsAtPosition<Box*>(X() + SpriteWidth(), Y());
			if (boxes.size() == 1)
			{
				std::vector<SolidObject*> solids = GetAllGameObjectsAtPosition<SolidObject*>(X() + (SpriteWidth() << 1), Y());
				if (solids.size() == 0)
				{
					SetImageSpeed(0.9f);
					SetSpeed(2);
					SetDirection(0);
					SetAlarm(0, 30);		//have to lower alarm and the SetSpeed() function to lessen the speed
					GetSprite()->setTexture(*SFMLTextureManager::GetInstance()->GetTexture("hero_right"));
					boxes[0]->SetImageSpeed(0.9f);
					boxes[0]->SetSpeed(2);
					boxes[0]->SetDirection(0);
					boxes[0]->SetAlarm(0, 30);
				}
			}
		}
	}
	
	if (SFMLKeyboard::GetInstance()->IsKeyDown(sf::Keyboard::Left) && (Alarm(0) < 0))
	{
		std::vector<SolidObject*> solids = GetAllGameObjectsAtPosition<SolidObject*>(X() - SpriteWidth(), Y());
		if (solids.empty() == true)
		{
			SetImageSpeed(0.9f);
			SetSpeed(6);
			SetDirection(180);
			SetAlarm(0, 10);
			GetSprite()->setTexture(*SFMLTextureManager::GetInstance()->GetTexture("hero_left"));
		}
		else
		{
			std::vector<Box*> boxes = GetAllGameObjectsAtPosition<Box*>(X() - SpriteWidth(), Y());
			if (boxes.size() == 1)
			{
				std::vector<SolidObject*> solids = GetAllGameObjectsAtPosition<SolidObject*>(X() - (SpriteWidth() << 1), Y());
				if (solids.size() == 0)
				{
					SetImageSpeed(0.9f);
					SetSpeed(2);
					SetDirection(180);
		 			SetAlarm(0, 30);		//have to lower alarm and the SetSpeed() function to lessen the speed
					GetSprite()->setTexture(*SFMLTextureManager::GetInstance()->GetTexture("hero_left"));
					boxes[0]->SetImageSpeed(0.9f);
					boxes[0]->SetSpeed(2);
					boxes[0]->SetDirection(180);
					boxes[0]->SetAlarm(0, 30);
				}
			}
		}
	}

	if (SFMLKeyboard::GetInstance()->IsKeyDown(sf::Keyboard::Up) && (Alarm(0) < 0))
	{
		std::vector<SolidObject*> solids = GetAllGameObjectsAtPosition<SolidObject*>(X(), Y() - SpriteHeight());
		if (solids.empty() == true)
		{
			SetImageSpeed(0.9f);
			SetSpeed(6);
			SetDirection(90);
			SetAlarm(0, 10);
			GetSprite()->setTexture(*SFMLTextureManager::GetInstance()->GetTexture("hero_up"));
		}
		else
		{
			std::vector<Box*> boxes = GetAllGameObjectsAtPosition<Box*>(X(), Y() - SpriteHeight());
			if (boxes.size() == 1)
			{
				std::vector<SolidObject*> solids = GetAllGameObjectsAtPosition<SolidObject*>(X(), Y() - (SpriteHeight() << 1));
				if (solids.size() == 0)
				{
					SetImageSpeed(0.9f);
					SetSpeed(2);
					SetDirection(90);
					SetAlarm(0, 30);		//have to lower alarm and the SetSpeed() function to lessen the speed
					GetSprite()->setTexture(*SFMLTextureManager::GetInstance()->GetTexture("hero_up"));
					boxes[0]->SetImageSpeed(0.9f);
					boxes[0]->SetSpeed(2);
					boxes[0]->SetDirection(90);
					boxes[0]->SetAlarm(0, 30);
				}
			}
		}
	}

	if (SFMLKeyboard::GetInstance()->IsKeyDown(sf::Keyboard::Down) && (Alarm(0) < 0))
	{
		std::vector<SolidObject*> solids = GetAllGameObjectsAtPosition<SolidObject*>(X(), Y() + SpriteHeight());
		if (solids.empty() == true)
		{
			SetImageSpeed(0.9f);
			SetSpeed(6);
			SetDirection(270);
			SetAlarm(0, 10);
			GetSprite()->setTexture(*SFMLTextureManager::GetInstance()->GetTexture("hero_down"));
		}
		else
		{
			std::vector<Box*> boxes = GetAllGameObjectsAtPosition<Box*>(X(), Y() + SpriteHeight());
			if (boxes.size() == 1)
			{
				std::vector<SolidObject*> solids = GetAllGameObjectsAtPosition<SolidObject*>(X(), Y() + (SpriteHeight() << 1));
				if (solids.size() == 0)
				{
					SetImageSpeed(0.9f);
					SetSpeed(2);
					SetDirection(270);
					SetAlarm(0, 30);		//have to lower alarm and the SetSpeed() function to lessen the speed
					GetSprite()->setTexture(*SFMLTextureManager::GetInstance()->GetTexture("hero_down"));
					boxes[0]->SetImageSpeed(0.9f);
					boxes[0]->SetSpeed(2);
					boxes[0]->SetDirection(270);
					boxes[0]->SetAlarm(0, 30);
				}
			}
		}
	}
}

void Hero::OnAlarm(int alarm)
{
	++Steps;
	SetImageSpeed(0);
	SetSpeed(0);

	bool won = true;
	std::vector<Goal*> goals = GetAllGameObjectsOfType<Goal*>();
	for (Goal* g : goals)
	{
		std::vector<Box*> boxes = GetAllGameObjectsAtPosition<Box*>(g->X(), g->Y());
		if (boxes.size() != 1)
		{
			won = false;
			break;
		}
	}

	if (won == true)
	{
		int f = 0;
	}
}

void Hero::Draw()
{
	SFMLObject::Draw();
	Font->Print(5, 5, "STEPS TAKEN: " + std::to_string(Steps));
}