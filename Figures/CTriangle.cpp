#include "CTriangle.h"
#include <fstream>


CTriangle::CTriangle(Point P1, Point P2, Point P3,GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	Type = "Triangle";
}

string CTriangle::getType()
{
	return Type;
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

void CTriangle::Save(ofstream& OutFile)
{
	
	string t = "Tri ang";
	string s = "   ";
	string dc;
	string fc;
	if (FigGfxInfo.DrawClr == BLACK)
	{
		fc = "Black";
	}
	else if (FigGfxInfo.DrawClr == BLUE)
	{
		dc = "Blue";
	}
	else if (FigGfxInfo.DrawClr == GREEN)
	{
		dc = "GREEN";
	}
	else if (FigGfxInfo.DrawClr == YELLOW)
	{
		dc = "Yellow";
	}
	else if (FigGfxInfo.DrawClr == RED)
	{
		dc = "RED";
	}
	else if (FigGfxInfo.DrawClr == ORANGE)
	{
		dc = "ORANGE";
	}
	else if (FigGfxInfo.DrawClr == NULL)
	{
		dc = "NOT FILLED";
	}
	
	if (FigGfxInfo.FillClr == BLACK)
	{
		fc = "Black";
	}
	else if (FigGfxInfo.DrawClr == BLUE)
	{
		fc = "Blue";
	}
	else if (FigGfxInfo.DrawClr == GREEN)
	{
		fc = "GREEN";
	}
	else if (FigGfxInfo.DrawClr == YELLOW)
	{
		fc = "Yellow";
	}
	else if (FigGfxInfo.DrawClr == RED)
	{
		fc = "RED";
	}
	else if (FigGfxInfo.DrawClr == ORANGE)
	{
		fc = "ORANGE";
	}
	else if (FigGfxInfo.DrawClr == NULL)
	{
		fc = "NOT FILLED";
	}
	

	
	
	OutFile << t << "   " << ID << s << Corner1.x << s << Corner1.y << s << Corner2.x << s << Corner2.y << s << Corner3.x << s << Corner3.y << s << dc << s << fc << endl;
	
}
