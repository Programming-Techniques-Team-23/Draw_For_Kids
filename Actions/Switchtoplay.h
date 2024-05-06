#pragma once
#include"Action.h"


class SwitchToPlay : public Action
{


public:
	SwitchToPlay(ApplicationManager*AM, int &);
   virtual void ReadActionParameters();
	virtual void Execute();
	~SwitchToPlay();

};