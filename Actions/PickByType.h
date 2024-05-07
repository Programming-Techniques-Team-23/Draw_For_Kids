#pragma once
#include "..\Figures\CFigure.h"
#include "Action.h"
class PickByType :public Action
{
	CFigure* Fig;
	Point P;
	int  FigureNumbers, RandomFigureNumbers, PickedFigureNumbers, Wrong, Correct;
	int Figures[4];
	void PrntScore(int);

public:
	PickByType(ApplicationManager*);
	~PickByType();
	void ReadActionParameters();
	void Execute();
};

