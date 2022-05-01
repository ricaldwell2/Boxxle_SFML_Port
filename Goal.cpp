#include "Goal.h"

Goal::Goal(float x, float y)
	: SFMLObject(x, y, "goal")	
{
	SetDepth(2);
}