#pragma once

#include "SFMLObject.h"

class SFMLFont : public SFMLObject
{
public:
	SFMLFont(const std::string& resource = "basic_font");

	//MUST BE CALLED IN DRAW EVENT!
	void Print(int x,
			   int y,
			   const std::string& text,
			   sf::Color tint = sf::Color::White,
			   float xScale = 1.0f,
			   float yScale = 1.0f);
};