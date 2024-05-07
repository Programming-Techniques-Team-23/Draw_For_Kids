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
string CCircle::Details() {
	int x1 = Centre.x;
	int y1 = Centre.y;
	int x2 = Radius.x;
	int y2 = Radius.y;
	string s = "   ";
	string message = Type + s;
	message += to_string(ID) + s;
	message += to_string(x1) + s;
	message += to_string(y1) + s;
	message += to_string(x2) + s;
	message += to_string(y2) + s;
	message += DrawColor + s + FillColor;
	return message;
}
void CCircle::Save(ofstream& OutFile)
{
	OutFile << Details() <<endl;	
}
