#pragma once

#include "SFMLRoom.h"

class BoxxleGameLevelRoom : public SFMLRoom
{
public:
	BoxxleGameLevelRoom(const std::string& filename,
						int levelNumber);

private:
	int LevelNumber;
};