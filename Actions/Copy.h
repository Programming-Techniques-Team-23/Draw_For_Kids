#pragma once
#include"Action.h"
#include"../ApplicationManager.h"
class Copy : public Action
{

public:
	Copy(ApplicationManager* AM);
	virtual void ReadActionParameters();
	virtual void Execute();
	~Copy();
};