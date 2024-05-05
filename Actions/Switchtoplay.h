#pragma once
#include"Action.h"


class SwitchToPlay : public Action
{
private:
	string FileName;

public:
	SwitchToPlay(ApplicationManager*AM);

	virtual void ReadActionParameters();
	virtual void Execute();
	~SwitchToPlay();
};