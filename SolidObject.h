#pragma once

#include "SFMLObject.h"

class SolidObject : public SFMLObject
{
public:
	SolidObject(float x, float y, const std::string& resource = "", int horizontalFrames = 1, int verticalFrames = 1);
};