#pragma once
#include"Action.h"

class ClearAll :public Action {

public:
	ClearAll(ApplicationManager* AM);
	virtual void ReadActionParameters();
	virtual void Execute();
	~ClearAll();
};