#include "CSquare.h"

CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Centre = P1;
}


void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSqaure to draw a square on the screen	
	pOut->DrawSquare(Corner1, Corner2, FigGfxInfo, Selected);
}