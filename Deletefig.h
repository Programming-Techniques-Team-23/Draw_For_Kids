#pragma once
#include"Actions/Action.h"
class Deletefig : public Action
{
private:
	
public:
	Deletefig(ApplicationManager* AM);
	virtual void ReadActionParameters();
	virtual void Execute();
};

