#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3,GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a triangle on the screen	
	pOut->DrawTri(Corner1, Corner2, Corner3,FigGfxInfo, Selected);
}
double CTriangle::area(Point a, Point b, Point c) {
	return abs((double)((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2.0));
}
bool CTriangle::pointchecker(int x, int y) {
	Point p = { x,y };
	double A = area(Corner1, Corner2, Corner3); 
	double A1 = area(p, Corner2, Corner3); 
	double A2 = area(Corner1, p, Corner3); 
	double A3 = area(Corner1, Corner2, p); 

	if (A == A1 + A2 + A3)
		return true;
	else
		return false;
}
