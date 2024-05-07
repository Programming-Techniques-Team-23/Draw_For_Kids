#include "CCircle.h"
#include <fstream>

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Centre = P1;
	Radius = P2;
	Type = "Circle";
}
string CCircle::getType() 
{ return Type; }
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

void CCircle::Save(ofstream& OutFile)
{
	string s ="   ";
	int x1 = Centre.x;
	int y1 = Centre.y;
	int x2 = Radius.x;
	int y2 = Radius.y;

	OutFile << Type << s << ID << s << x1 << s << y1 << s << x2 << s << y2 << s << DrawColor << s << FillingColor <<endl;
	
}
