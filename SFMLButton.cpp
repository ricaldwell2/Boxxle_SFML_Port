#include "SFMLFont.h"
#include "SFMLMouse.h"
#include "SFMLButton.h"

SFMLButton::SFMLButton(float x, 
					   float y, 
					   const std::string& spriteResource, 
					   void (*callback)(),
					   const std::string& text,
					   sf::Color off_color,
					   sf::Color on_color,
					   const std::string& fontResource)
	: SFMLObject(x, y, spriteResource, 2, 1),
	  Callback(callback),
	  Font(new SFMLFont(fontResource)),
	  Text(text),
	  OffColor(off_color),
	  OnColor(on_color)
{
	SetImageSpeed(0.1f);
	//Nothing here...
}

SFMLButton::~SFMLButton()
{
	delete Font;
}

void SFMLButton::Step()			//possible portion for button bug
{
	sf::Vector2i mouse = SFMLMouse::GetInstance()->GetMousePosition();
	SetImageIndex(0);
	if (IsPointWithinSpriteBounds(mouse.x, mouse.y) == true)
	{
		SetImageIndex(1); 
		if (SFMLMouse::GetInstance()->IsButtonPressed(sf::Mouse::Left) == true)
		{
			Callback();
		}
	}
}

void SFMLButton::Draw()
{
	SFMLObject::Draw();
	sf::Color DrawColor = (ImageIndex() == 0) ? OffColor : OnColor;
	Font->Print(X() + 45, Y() + 52, Text, DrawColor, 3, 3);
}