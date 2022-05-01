#include <iostream>
#include "SFMLGame.h"
#include "SFMLObject.h"
#include "SFMLTextureManager.h"

SFMLObject::SFMLObject(float x, 
					   float y, 
					   const std::string& resource, 
					   int horizontalFrames, 
					   int verticalFrames)
	:Sprite(new sf::Sprite()),
	 StartPosition(x, y),
	 PreviousPosition(x, y),
	 IsVisible(true),
	 DepthValue(0.0),
	 Alarms(5, -1),
	 SpeedVector(0.0f, 0.0f),
	 HorizontalFrames(horizontalFrames),
	 VerticalFrames(verticalFrames),
	 Image_Index(0),
	 Image_Speed(0)
{
	if (resource != "")
	{
		sf::Texture* Texture =
			SFMLTextureManager::GetInstance()->GetTexture(resource);

		Sprite->setTexture(*Texture);
		Sprite->setPosition(x, y);
	}
}

SFMLObject::~SFMLObject()
{
	delete Sprite;
	Sprite = nullptr;
}

void SFMLObject::Step()
{
	//Animations
	SetImageIndex(ImageIndex() + ImageSpeed());

	//Speed
	Sprite->setPosition(Sprite->getPosition() + SpeedVector);

	//Alarm
	for (std::size_t i = 0; i < Alarms.size(); ++i)
	{
		if (Alarms[i] > 0)
		{
			--Alarms[i];
			if (Alarms[i] == 0)
			{
				OnAlarm(i);
				Alarms[i] = -1;
			}
		}
	}
}

void SFMLObject::Draw()
{
	if (Sprite != nullptr)
	{
		if (IsVisible == true)
		{
			int x = static_cast<int>(ImageIndex()) % HorizontalFrames;
			int y = static_cast<int>(ImageIndex()) / HorizontalFrames;
			Sprite->setTextureRect(sf::IntRect(x * SpriteWidth(), y * SpriteHeight(), SpriteWidth(), SpriteHeight()));
			SFMLGame::GetInstance()->GetWindow()->draw(*Sprite);
			std::cout << x << " " << y << std::endl;
		}
	}
}

sf::Sprite* SFMLObject::GetSprite()
{
	return Sprite;
}

float SFMLObject::X()
{
	return Sprite->getPosition().x;
}

void SFMLObject::SetX(float x)
{
	Sprite->setPosition(x, Sprite->getPosition().y);
}

float SFMLObject::Y()
{
	return Sprite->getPosition().y;
}

void SFMLObject::SetY(float y)
{
	Sprite->setPosition(Sprite->getPosition().x, y);
}

float SFMLObject::XStart()
{
	return StartPosition.x;
}

void SFMLObject::SetXStart(float x)
{
	StartPosition.x = x;
}

float SFMLObject::YStart()
{
	return StartPosition.y;
}

void SFMLObject::SetYStart(float y)
{
	StartPosition.y = y;
}

float SFMLObject::XPrevious()
{
	return PreviousPosition.x;
}

void SFMLObject::SetXPrevious(float x)
{
	PreviousPosition.x = x;
}

float SFMLObject::YPrevious()
{
	return PreviousPosition.y;
}

void SFMLObject::SetYPrevious(float y)
{
	PreviousPosition.y = y;
}

bool SFMLObject::Visible()
{
	return IsVisible;
}

void SFMLObject::SetVisibile(bool visible)
{
	IsVisible = visible;
}

float SFMLObject::Depth()
{
	return DepthValue;
}

void SFMLObject::SetDepth(float depth)
{
	DepthValue = depth;
}

int SFMLObject::Alarm(int alarm)
{
	return Alarms[alarm];
}

void SFMLObject::SetAlarm(int alarm, int value)
{
	Alarms[alarm] = value;
}

void SFMLObject::OnAlarm(int alarm)
{
	//Do Nothing...
}

float SFMLObject::HSpeed()
{
	return SpeedVector.x;
}

void SFMLObject::SetHSpeed(float hspeed)
{
	SpeedVector.x = hspeed;
}

float SFMLObject::VSpeed()
{
	return SpeedVector.y;
}

void SFMLObject::SetVSpeed(float vspeed)
{
	SpeedVector.y = vspeed;
}

float SFMLObject::Speed()
{
	return hypot(SpeedVector.x, SpeedVector.y);
}

void SFMLObject::SetSpeed(float NewSpeed)
{
	float OldSpeed = Speed();
	if (OldSpeed != 0.0f)
	{
		float factor = NewSpeed / OldSpeed;
		SpeedVector *= factor;
	}
	else 
	{
		SpeedVector.x = NewSpeed;
	}
}

float SFMLObject::Direction()		//Getting the direction in degrees
{
	//DEGREES = 180 * RADIANS / PI
	return 180.0f * atan2(-SpeedVector.y, SpeedVector.x) / 3.1415926535f;
}

void SFMLObject::SetDirection(float direction)
{
	//RADIANS = DEGREES * PI / 180
	float radians = direction * 3.1415926535 / 180.0f;
	float speed = Speed();
	SpeedVector = sf::Vector2f(speed * cos(radians), -speed * sin(radians));
}

float SFMLObject::ImageIndex()
{
	return Image_Index;
}

void SFMLObject::SetImageIndex(float value)
{
	value = fmod(value, HorizontalFrames * VerticalFrames);
	if (value < 0)
	{
		value += (HorizontalFrames * VerticalFrames);
	}
	Image_Index = value;
}

float SFMLObject::ImageSpeed()
{
	return Image_Speed;
}

void SFMLObject::SetImageSpeed(float value)
{
	Image_Speed = value;
}

int SFMLObject::SpriteWidth()
{
	return Sprite->getTexture()->getSize().x / HorizontalFrames;
}

int SFMLObject::SpriteHeight()
{
	return Sprite->getTexture()->getSize().y / VerticalFrames;
}

bool SFMLObject::IsPointWithinSpriteBounds(int x, int y)
{
	if ((x >= Sprite->getPosition().x) &&
		(x < Sprite->getPosition().x + SpriteWidth()) &&
		(y >= Sprite->getPosition().y) &&
		(y < Sprite->getPosition().y + SpriteHeight()))
	{
		return true;
	}
	return false;
}
