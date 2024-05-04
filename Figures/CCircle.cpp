#include "CCircle.h"

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Centre = P1;
	Radius = P2;
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCirc to draw a circle on the screen	
	pOut->DrawCirc(Centre, Radius, FigGfxInfo, Selected);
}
bool CCircle::pointchecker(int x, int y)
{
	int dsq = (x - Centre.x) ^ 2 + (y - Centre.y) ^ 2;
	int radius = (Radius.x - Centre.x) ^ 2 + (Radius.y - Centre.y) ^ 2;
	if (dsq <= radius)
		return true;
	else
		return false;
}