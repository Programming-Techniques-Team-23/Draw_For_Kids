#pragma once
#include"Action.h"
class Cut :public Action {
private:
	GfxInfo figcut;
public:
	Cut(ApplicationManager* AM);
	virtual void ReadActionParameters();
	virtual void Execute();
	~Cut();
};