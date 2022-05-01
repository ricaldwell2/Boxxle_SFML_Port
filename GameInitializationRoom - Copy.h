#pragma once

#include "SFMLRoom.h"
#include "SFMLGame.h"

//---------------------------
//CONSIDER THIS FILE READONLY
//---------------------------

class GameInitializationRoom : public SFMLRoom
{
public:
	GameInitializationRoom();

	virtual void Step() override;
};