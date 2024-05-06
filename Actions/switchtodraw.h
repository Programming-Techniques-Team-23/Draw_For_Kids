#pragma once
#include"Action.h"

class SwitchToDraw :public Action {
private:
	int* Mode;
public:
	SwitchToDraw(ApplicationManager* AM, int *);
	virtual void ReadActionParameters();
	virtual void Execute();
	~SwitchToDraw();
};