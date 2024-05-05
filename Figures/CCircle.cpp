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
	int dsq = (x - Centre.x)* (x - Centre.x) + (y - Centre.y) * (y - Centre.y);
	int radius = (Radius.x - Centre.x) * (Radius.x - Centre.x) + (Radius.y - Centre.y) * (Radius.y - Centre.y);
	if (dsq <= radius)
		return true;
	else
		return false;
}