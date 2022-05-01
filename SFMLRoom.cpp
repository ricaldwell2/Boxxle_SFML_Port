#include "SFMLGame.h"
#include "SFMLRoom.h"

SFMLRoom::SFMLRoom()
	:  Objects()
{
	//Getting ready for SFMLObject
}

SFMLRoom::~SFMLRoom()
{
	for (SFMLObject* o : Objects)
	{
		delete o;
	}
	Objects.clear();
}

void SFMLRoom::Step()
{
	for (SFMLObject* o : Objects)
	{
		o->Step();
	}
}

bool LessThanOperator(SFMLObject* lhs, SFMLObject* rhs)
{
	return lhs->Depth() < rhs->Depth();
}

void SFMLRoom::Draw()
{
	std::sort(Objects.begin(), Objects.end(), LessThanOperator);

	for (SFMLObject* o : Objects)
	{
		o->Draw();	
	}
}

void SFMLRoom::InstanceCreate(SFMLObject* Object)
{
	Objects.push_back(Object);
}

void SFMLRoom::ChangeRoom(SFMLRoom* NextRoom)
{
	SFMLGame* g = SFMLGame::GetInstance();
	g->ChangeRoom(NextRoom);
}
