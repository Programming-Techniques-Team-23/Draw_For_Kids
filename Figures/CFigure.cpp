#include "CFigure.h"
#include <fstream>

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

GfxInfo CFigure::GetGfxInfo() const
{
	return FigGfxInfo;
}

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
//Hides Figures
void CFigure::Hide()
{
	PlayHidden = true;
}
//Shows Figures
void CFigure::Show()
{
	PlayHidden = false;
}


void CFigure::Setid(int x)
{
	ID = x;
}

int CFigure::getid()
{
	return ID;
}

