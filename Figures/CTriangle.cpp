#include "CTriangle.h"
#include <fstream>
#include "../Actions/LoadAction.h"
using namespace std;


CTriangle::CTriangle(Point P1, Point P2, Point P3,GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	Type = "Triangle";
}

CTriangle::CTriangle()
{
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
string CTriangle::Details() {
	int x1 = Corner1.x;
	int y1 = Corner1.y;
	int x2 = Corner2.x;
	int y2 = Corner2.y;
	int x3 = Corner3.x;
	int y3 = Corner3.y;
	string s = "   ";
	string message = Type + s;
	message += to_string(ID) + s;
	message += to_string(x1) + s;
	message += to_string(y1) + s;
	message += to_string(x2) + s;
	message += to_string(y2) + s;
	message += to_string(x3) + s;
	message += to_string(y3) + s;
	message += DrawColor + s + FillColor;
	return message;
}
void CTriangle::Save(ofstream& OutFile)
{
	{
		OutFile.app;
		OutFile << Type << " " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << Corner3.x << " " << Corner3.y << " " << DrawColor << " " << FillColor << endl;
	}
}
void CTriangle::Load(ifstream& Infile)
{
	Infile >>ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y >> DrawColor >> FillColor;
	
	FigGfxInfo.DrawClr = stringtoclr(DrawColor);
	FigGfxInfo.FillClr = stringtoclr(FillColor);
}
void CTriangle::setcor1(Point f)
{
	Corner1 = f;
}

void CTriangle::setcor2(Point g)
{
	Corner2 = g;
}

void CTriangle::setcor3(Point h)
{
	Corner3 = h;
}

void CTriangle::setgfxinfo(GfxInfo gi)
{
	FigGfxInfo = gi;
}

Point CTriangle::getcor1()
{
	return Corner1;
}

Point CTriangle::getcor2()
{
	return Corner2;
}

Point CTriangle::getcor3()
{
	return Corner3;
}

GfxInfo CTriangle::getgfxinfo()
{
	return FigGfxInfo;
}