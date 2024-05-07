#pragma once
#include "..\Figures\CFigure.h"

#include "Action.h"
class PickByType :
	public Action
{
	CFigure* Fig;
	Point P;
	int  no_figs, rand_fig_no, picked_fig_no, wrgSel, rigSel;
	int figs[5];
	void PrntScore(int);

public:
	PickByType(ApplicationManager*);
	~PickByType();
	void ReadActionParameters();
	void Execute();
};

