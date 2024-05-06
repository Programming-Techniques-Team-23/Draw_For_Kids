#include "CSquare.h"
#include <fstream>


CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Centre = P1;
}


void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSqaure to draw a square on the screen	
	pOut->DrawSquare(Centre, FigGfxInfo, Selected);
}
bool CSquare::pointchecker(int x, int y)
{
    int xmin = Centre.x - 100; 
    int xmax = Centre.x + 100; 
    int ymin = Centre.y - 100; 
    int ymax = Centre.y + 100; 

    if ((x >= xmin && x <= xmax) && (y >= ymin && y <= ymax))
        return true;
    else
        return false;
}

void CSquare::Save(ofstream& OutFile)
{
   
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

	OutFile << "Squr" << s << ID << s<<Centre.x << s <<Centre.y<<s << dc << s << fc << endl;

}
