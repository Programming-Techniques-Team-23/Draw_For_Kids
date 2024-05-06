#include "CFigure.h"
#include <fstream>

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	if (FigGfxInfo.DrawClr == BLACK)
	{
		DrawColor = "Black";
	}
	else if (FigGfxInfo.DrawClr == BLUE)
	{
		DrawColor = "Blue";
	}
	else if (FigGfxInfo.DrawClr == GREEN)
	{
		DrawColor = "GREEN";
	}
	else if (FigGfxInfo.DrawClr == YELLOW)
	{
		DrawColor = "Yellow";
	}
	else if (FigGfxInfo.DrawClr == RED)
	{
		DrawColor = "RED";
	}
	else if (FigGfxInfo.DrawClr == ORANGE)
	{
		DrawColor = "ORANGE";
	}
	else if (FigGfxInfo.DrawClr == NULL)
	{
		DrawColor = "NOT FILLED";
	}

	if (FigGfxInfo.FillClr == BLACK)
	{
		FillColor = "Black";
	}
	else if (FigGfxInfo.DrawClr == BLUE)
	{
		FillColor = "Blue";
	}
	else if (FigGfxInfo.DrawClr == GREEN)
	{
		FillColor = "GREEN";
	}
	else if (FigGfxInfo.DrawClr == YELLOW)
	{
		FillColor = "Yellow";
	}
	else if (FigGfxInfo.DrawClr == RED)
	{
		FillColor = "RED";
	}
	else if (FigGfxInfo.DrawClr == ORANGE)
	{
		FillColor = "ORANGE";
	}
	else if (FigGfxInfo.DrawClr == NULL)
	{
		FillColor = "NOT FILLED";
	}
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

void CFigure::Setid(int x)
{
	ID = x;
}

int CFigure::getid()
{
	return ID;
}

