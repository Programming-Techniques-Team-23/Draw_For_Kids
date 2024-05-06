#include "CCircle.h"
#include <fstream>

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

void CCircle::Save(ofstream& OutFile)
{
	string s ="   ";
	string c = "circ";
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
	int x1 = Centre.x;
	int y1 = Centre.y;
	int x2 = Radius.x;
	int y2 = Radius.y;

	OutFile << c << "   " << ID << "   " << x1 << "   " << y1 << "   " << x2 << "   " << y2 << "   " << dc << "   " << fc<<endl;
}
