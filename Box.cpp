#include "Box.h"
#include "SFMLGame.h"

Box::Box(float x, float y)
	: SolidObject(x, y, "box")
{
	SetDepth(1);
}

void Box::OnAlarm(int alarm)
{
	SetSpeed(0);
}