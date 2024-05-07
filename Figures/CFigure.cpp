#include "CFigure.h"
#include <fstream>

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	FillColor = "Not Filled";
	ChngDrawClr(BLUE);
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; 
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
	DrawColor = "Green";
}
else if (FigGfxInfo.DrawClr == YELLOW)
{
	DrawColor = "Yellow";
}
else if (FigGfxInfo.DrawClr == RED)
{
	DrawColor = "Red";
}
else if (FigGfxInfo.DrawClr == ORANGE)
{
	DrawColor = "Orange";
}
else if (FigGfxInfo.DrawClr == NULL)
{
	DrawColor = "Not Filled";
}
}

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
	if (FigGfxInfo.isFilled) {
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
			FillColor = "Green";
		}
		else if (FigGfxInfo.DrawClr == YELLOW)
		{
			FillColor = "Yellow";
		}
		else if (FigGfxInfo.DrawClr == RED)
		{
			FillColor = "Red";
		}
		else if (FigGfxInfo.DrawClr == ORANGE)
		{
			FillColor = "Orange";
		}
	}
	else
	{
		FillColor = "Not Filled";
	}
}

void CFigure::Setid(int x)
{
	ID = x;
}

int CFigure::getid()
{
	return ID;
}

