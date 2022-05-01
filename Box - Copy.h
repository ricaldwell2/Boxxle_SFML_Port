#pragma once

#include "SolidObject.h"

class Box : public SolidObject
{
public:
	Box(float x, float y);

	virtual void OnAlarm(int alarm);
};