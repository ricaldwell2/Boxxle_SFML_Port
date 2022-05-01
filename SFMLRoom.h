#pragma once

#include <vector>
#include "SFMLObject.h"
#include "SFMLRoom.h"

//Base class for all room objects
class SFMLRoom
{
public:
	SFMLRoom();				//constructor
	
	virtual ~SFMLRoom();	//destructor

	virtual void Step();
	virtual void Draw();

	void InstanceCreate(SFMLObject* Object);
	void ChangeRoom(SFMLRoom* NextRoom);
	
	template <typename T>
	std::vector<T> GetAllGameObjectsAtPosition(float x, float y);

	template <typename T>
	std::vector<T> GetAllGameObjectsOfType();

private:
	std::vector<SFMLObject*> Objects;
};

//Templated functions occur in the .h file instead of the initilization/.cpp files
template <typename T>
std::vector<T> SFMLRoom::GetAllGameObjectsAtPosition(float x, float y)
{
	std::vector<T> objects;
	for (SFMLObject* o : Objects)
	{
		if (o->IsPointWithinSpriteBounds(x, y) == true)
		{
			T cast = dynamic_cast<T>(o);
			if (cast != nullptr)
			{
				if (o->IsPointWithinSpriteBounds(x, y) == true)
				{
					objects.push_back(cast);
				}	
			}
		}
	}
	return objects;
}

template<typename T>
std::vector<T> SFMLRoom::GetAllGameObjectsOfType()
{
	std::vector<T> objects;
	for (SFMLObject* o : Objects)
	{
		T cast = dynamic_cast<T>(o);
		if (cast != nullptr)
		{
			objects.push_back(cast);
		}
	}
	return objects;
}