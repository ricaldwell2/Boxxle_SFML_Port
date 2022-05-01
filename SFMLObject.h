#pragma once

#include <SFML/Graphics.hpp>

//Base class for all game objects
class SFMLObject
{
public:
	SFMLObject(float x, float y, const std::string& resource = "", int horizontalFrames = 1, int verticalFrames = 1);

	virtual ~SFMLObject();

	virtual void Step();
	virtual void Draw();

	sf::Sprite* GetSprite();

	float X();
	void SetX(float x);

	float Y();
	void SetY(float y);

	float XStart();
	void SetXStart(float x);

	float YStart();
	void SetYStart(float y);

	float XPrevious();
	void SetXPrevious(float x);

	float YPrevious();
	void SetYPrevious(float y);

	bool Visible();
	void SetVisibile(bool visible);

	float Depth();
	void SetDepth(float depth);

	int Alarm(int alarm);
	void SetAlarm(int alarm, int value);
	virtual void OnAlarm(int alarm);

	float HSpeed();
	void SetHSpeed(float hspeed);

	float VSpeed();
	void SetVSpeed(float vspeed);

	float Speed();
	void SetSpeed(float NewSpeed);

	float Direction();
	void SetDirection(float direction);

	float ImageIndex();
	void SetImageIndex(float value);

	float ImageSpeed();
	void SetImageSpeed(float value);

	int	SpriteWidth();
	int SpriteHeight();

	bool IsPointWithinSpriteBounds(int x, int y);

	template <typename T>
	std::vector<T> GetAllGameObjectsAtPosition(float x, float y);

	template <typename T>
	std::vector<T> GetAllGameObjectsOfType();

private:
	sf::Sprite* Sprite;
	sf::Vector2f StartPosition;
	sf::Vector2f PreviousPosition;
	bool IsVisible;
	float DepthValue;
	std::vector<int> Alarms;
	sf::Vector2f SpeedVector;
	int HorizontalFrames;
	int VerticalFrames;
	float Image_Index;
	float Image_Speed;
};

template<typename T>
std::vector<T> SFMLObject::GetAllGameObjectsAtPosition(float x, float y)
{
	return SFMLGame::GetInstance()->GetCurrentRoom()->GetAllGameObjectsAtPosition<T>(x, y);
}

template<typename T>
std::vector<T> SFMLObject::GetAllGameObjectsOfType()
{
	return SFMLGame::GetInstance()->GetCurrentRoom()->GetAllGameObjectsOfType<T>();
}